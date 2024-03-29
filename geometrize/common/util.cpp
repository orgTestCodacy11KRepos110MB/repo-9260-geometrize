#include "util.h"

#include <cassert>
#include <cmath>
#include <csignal>
#include <fstream>
#include <random>

#include <QApplication>
#include <QClipboard>
#include <QCoreApplication>
#include <QCursor>
#include <QDateTime>
#include <QDesktopServices>
#include <QDir>
#include <QDirIterator>
#include <QFileInfo>
#include <QGuiApplication>
#include <QMessageBox>
#include <QObject>
#include <QPixmap>
#include <QPoint>
#include <QScreen>
#include <QStandardPaths>
#include <QTextStream>
#include <QUrl>
#include <QUuid>
#include <QWindow>

#include "dialog/imagetaskwindow.h"
#include "dialog/scriptconsole.h"
#include "script/command.h"
#include "script/commandhandler.h"

#include "geometrize/commonutil.h"

#ifdef _MSC_VER
#include <intrin.h> // For debugbreak
#endif

namespace
{

std::vector<QWidget*> getImageTaskWidgets()
{
    const std::vector<geometrize::dialog::ImageTaskWindow*> windows = geometrize::dialog::ImageTaskWindow::getExistingImageTaskWindows();
    std::vector<QWidget*> widgets;
    for(auto* w : windows) {
        widgets.emplace_back(w);
    }
    return widgets;
}

int getPrimaryScreenIdx()
{
    QScreen* primaryScreen = QGuiApplication::primaryScreen();
    int screenIdx = 0;
    for(QScreen* s : QGuiApplication::screens()) {
        if(primaryScreen == s) {
            break;
        }
        screenIdx++;
    }
    return screenIdx;
}

}

namespace geometrize
{

namespace util
{

void debugBreak()
{
#ifdef _MSC_VER
    __debugbreak();
#elif __MINGW32__
    // Not sure how to break here...
    assert(0 && "Mingw32 debug break");
#else
    raise(SIGTRAP);
#endif
}

void printToConsole(const std::string& str)
{
    QTextStream(stdout) << QString::fromStdString(str);
}

void printToAllScriptConsoleWidgets(const std::string& str)
{
    const auto& allWidgets = QApplication::topLevelWidgets();
    for (const auto& widget : allWidgets) {
        const auto& consoles = widget->findChildren<geometrize::dialog::ScriptConsole*>();
        for(auto& console : consoles) {
            console->appendString(str);
        }
    }
}

void messageBox(const std::string& str)
{
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(str));
    msgBox.exec();
}

void processApplicationEvents()
{
    QCoreApplication* app = QCoreApplication::instance();
    if(app == nullptr) {
        assert(0 && "Application instance pointer is null");
        return;
    }
    app->processEvents();
}

bool fileExists(const std::string& filePath)
{
    return QFile(QString::fromStdString(filePath)).exists();
}

bool directoryExists(const std::string& dirPath)
{
    return QDir(QString::fromStdString(dirPath)).exists();
}

bool directoriesExist(const std::vector<std::string>& dirPaths)
{
    return std::all_of(dirPaths.begin(), dirPaths.end(), directoryExists);
}

bool directoryContainsFile(const std::string& dirPath, const std::string& fileName)
{
    const QString qFileName{QString::fromStdString(fileName)};
    QDirIterator it(QString::fromStdString(dirPath));
    while(it.hasNext()) {
        it.next();
        if(QFileInfo(it.filePath()).isFile()) {
            if(it.fileName() == qFileName) {
                return true;
            }
        }
    }
    return false;
}

bool createDirectory(const std::string& dirPath)
{
    return QDir().mkpath(QString::fromStdString(dirPath));
}

std::string readFileAsString(const std::string& filePath)
{
    QFile file(QString::fromStdString(filePath));

    if(file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return QString(file.readAll()).toStdString();
    }

    return "";
}

std::vector<std::string> getFilePathsForDirectory(const std::string& dirPath)
{
    std::vector<std::string> files;

    QDirIterator it(QString::fromStdString(dirPath));
    while(it.hasNext()) {
        it.next();
        if(QFileInfo(it.filePath()).isFile()) {
            files.push_back(it.filePath().toStdString());
        }
    }
    return files;
}

std::vector<std::string> getSubdirectoriesForDirectory(const std::string& dirPath)
{
    std::vector<std::string> files;

    QDirIterator it(QString::fromStdString(dirPath));
    while(it.hasNext()) {
        it.next();
        if(QFileInfo(it.filePath()).isDir()) {
            files.push_back(it.filePath().toStdString());
        }
    }
    return files;
}

inline bool endsWith(const std::string& value, const std::string& ending)
{
    if (value.length() >= ending.length()) {
        return (0 == value.compare (value.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

std::vector<std::string> getFilesWithExtension(const std::string& dirPath, const std::string& extension)
{
    std::vector<std::string> files{getFilePathsForDirectory(dirPath)};

    files.erase(std::remove_if(files.begin(), files.end(), [&extension](const std::string& s) {
        return !endsWith(s, extension);
    }), files.end());

    return files;
}

std::string getFirstFileWithExtension(const std::string& dirPath, const std::string& extension)
{
    const std::vector<std::string> files{getFilesWithExtension(dirPath, extension)};

    if(files.empty()) {
        return "";
    }
    return files.front();
}

std::string getFirstFileWithExtensions(const std::string& dirPath, const std::vector<std::string>& extensions)
{
    for(const std::string& ext : extensions) {
        const std::string s{getFirstFileWithExtension(dirPath, ext)};
        if(!s.empty()) {
            return s;
        }
    }

    return "";
}

std::vector<std::string> getScriptsForPath(const std::string& dirPath)
{
    std::vector<std::string> scripts;
    if(!util::directoryExists(dirPath)) {
        assert(0 && "Script directory does not exist");
        return scripts;
    }

    QDirIterator it(QString::fromStdString(dirPath), { "*.chai" }, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        scripts.push_back(it.next().toStdString());
    }

    return scripts;
}

std::vector<std::string> getScriptsForPaths(const std::vector<std::string>& dirPaths)
{
    std::vector<std::string> scripts;
    for(const auto& dirPath : dirPaths) {
        const auto newScripts = getScriptsForPath(dirPath);
        scripts.insert(scripts.end(), newScripts.begin(), newScripts.end());
    }
    return scripts;
}

std::string getDirectoryForFilePath(const std::string& filePath)
{
    const QFileInfo fileInfo{QString::fromStdString(filePath)};

    if(!fileInfo.exists()) {
        assert(0 && "File does not exist");
    }

    return fileInfo.absoluteDir().absolutePath().toStdString();
}

std::string getFileNameForFilePath(const std::string& filePath)
{
    return QFileInfo(QString::fromStdString(filePath)).fileName().toStdString();
}

bool openInDefaultApplication(const std::string& path)
{
    return QDesktopServices::openUrl(QUrl::fromUserInput(QString::fromStdString(path)));
}

bool revealInDefaultApplication(const std::string& path)
{
    const QUrl directoryPath{QUrl::fromUserInput(QString::fromStdString(path)).adjusted(QUrl::RemoveFilename)};
    return QDesktopServices::openUrl(directoryPath);
}

void clearGlobalClipboard()
{
    QApplication::clipboard()->clear();
}

std::string getGlobalClipboardText()
{
    return QApplication::clipboard()->text().toStdString();
}

void setGlobalClipboardText(const std::string& text)
{
    QApplication::clipboard()->setText(QString::fromStdString(text));
}

bool stringBeginsWith(const std::string& str, const std::string& prefix)
{
    return str.size() >= prefix.size() && std::equal(prefix.begin(), prefix.end(), str.begin());
}

bool stringEndsWith(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

std::string getApplicationDirectoryLocation()
{
    return QCoreApplication::applicationDirPath().toStdString();
}

std::string getAppDataLocation()
{
    return QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation).toStdString();
}

std::string getHomeDirectoryLocation()
{
    return QStandardPaths::writableLocation(QStandardPaths::HomeLocation).toStdString();
}

std::string getDesktopDirectoryLocation()
{
    return QStandardPaths::writableLocation(QStandardPaths::DesktopLocation).toStdString();
}

bool writeStringToFile(const std::string& str, const std::string& path)
{
    std::ofstream out(path, std::ios::trunc | std::ios::out);
    if(!out.is_open()) {
        return false;
    }

    if(out) {
        out << str;
    }

    out.close();

    if(!out) {
        return false;
    }

    return true;
}

std::string percentEncode(const std::string& str)
{
    const QString s{QString::fromStdString(str)};
    const QString percentEncoded{QUrl::toPercentEncoding(s)};
    return percentEncoded.toStdString();
}

int randomInRange(const int lower, const int upper)
{
    assert(lower <= upper);
    return geometrize::commonutil::randomRange(lower, upper);
}

std::vector<std::string> split(const std::string& s, const char delimiter)
{
    std::vector<std::string> elements;
    split(s, delimiter, std::back_inserter(elements));
    return elements;
}

int getCursorX()
{
    return QCursor::pos().x();
}

int getCursorY()
{
    return QCursor::pos().y();
}

void setCursorPos(const int x, const int y)
{
    QCursor::setPos(x, y);
}

std::string getOperatingSystemProductType()
{
    return QSysInfo::productType().toStdString();
}

bool saveWidgetScreenshot(const std::string& path, QWidget* widget)
{
    return widget->grab().save(QString::fromStdString(path), "png");
}

std::vector<std::string> getAllNamedWidgets()
{
    std::vector<std::string> names;
    const QWidgetList allWidgets = QApplication::allWidgets();
    for (QWidget* widget : allWidgets) {
        if(widget && !widget->objectName().isEmpty()) {
            names.emplace_back(widget->objectName().toStdString());
        }
    }
    return names;
}

std::vector<std::string> getAllNamedGeometrizeWidgets()
{
    std::vector<std::string> names;
    const QWidgetList allWidgets = QApplication::allWidgets();
    for (QWidget* widget : allWidgets) {
        if(widget && widget->objectName().contains("geometrize")) {
            names.emplace_back(widget->objectName().toStdString());
        }
    }
    return names;
}

QWidget* getWidgetByName(const std::string& widgetName)
{
    const QWidgetList allWidgets = QApplication::allWidgets();
    for (QWidget* widget : allWidgets) {
        if(widget && widget->objectName().toStdString() == widgetName) {
            return widget;
        }
    }
    return nullptr;
}

std::vector<std::string> getAllNamedCommandHandlers()
{
    const auto& handlers = geometrize::script::CommandHandler::allCommandHandlers;
    std::vector<std::string> names;
    for(const auto& h : handlers) {
        names.emplace_back(h->getCommandHandlerName());
    }
    return names;
}

geometrize::script::CommandHandler* getCommandHandlerByName(const std::string& name)
{
    const auto& handlers = geometrize::script::CommandHandler::allCommandHandlers;
    for(const auto& h : handlers) {
        if(h->getCommandHandlerName() == name)
        {
            return h;
        }
    }
    return nullptr;
}

void sendCommand(const std::string& target, const std::string& command)
{
    const auto& handlers = geometrize::script::CommandHandler::allCommandHandlers;
    for(const auto& h : handlers) {
        if(h->getCommandHandlerName() == target)
        {
            h->handleCommand(geometrize::script::Command(command));
            return;
        }
    }
}

void sendCommand(const std::string& target, geometrize::script::Command& command)
{
    const auto& handlers = geometrize::script::CommandHandler::allCommandHandlers;
    for(const auto& h : handlers) {
        if(h->getCommandHandlerName() == target)
        {
            h->handleCommand(geometrize::script::Command(command));
            return;
        }
    }
}

void broadcastCommand(const std::string& command)
{
    const auto& handlers = geometrize::script::CommandHandler::allCommandHandlers;
    for(const auto& h : handlers) {
        h->handleCommand(geometrize::script::Command(command));
    }
}

void broadcastCommand(geometrize::script::Command& command)
{
    const auto& handlers = geometrize::script::CommandHandler::allCommandHandlers;
    for(const auto& h : handlers) {
        h->handleCommand(command);
    }
}

std::string getFormattedTimestamp(const std::string& formatString)
{
    return QDateTime::currentDateTime().toString(QString::fromStdString(formatString)).toStdString();
}

std::string getFilenameTimestamp()
{
    return getFormattedTimestamp("yyyy_MM_dd_hh_mm_ss_zzz");
}

std::string getUuidString()
{
    return QUuid::createUuid().toString().toStdString();
}

void setWidgetSize(QWidget* widget, int width, int height)
{
    widget->resize(width, height);
}

void setWidgetPosition(QWidget* widget, int x, int y)
{
    widget->move(x, y);
}

void arrangeWidgetsInGrid(const std::vector<QWidget*>& widgets, int centerX, int centerY, int xDim, int yDim, int resizeX, int resizeY)
{
    int idx = 0;
    const int width = xDim * resizeX;
    const int height = yDim * resizeY;
    for(int y = 0; y < yDim; y++) {
        for(int x = 0; x < xDim; x++) {
            if(idx >= widgets.size()) {
                continue;
            }
            if(QWidget* widget = widgets[idx]) {
                setWidgetSize(widget, resizeX, resizeY);
                setWidgetPosition(widget, (centerX - width / 2) + x * resizeX, (centerY - height / 2) + y * resizeY);
            }
            idx++;
        }
    }
}

void arrangeImageTaskWidgetsInGrid(int centerX, int centerY, int xDim, int yDim, int resizeX, int resizeY)
{
    arrangeWidgetsInGrid(getImageTaskWidgets(), centerX, centerY, xDim, yDim, resizeX, resizeY);
}

void arrangeWidgetsInGridOnMonitor(const std::vector<QWidget*>& widgets, int screenIdx, int resizeX, int resizeY)
{
    QList<QScreen*> screens = QGuiApplication::screens();
    if(screenIdx >= screens.size()) {
        return;
    }
    QRect screenGeometry = screens.at(screenIdx)->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    arrangeWidgetsInGrid(widgets, screenGeometry.x() + width / 2, screenGeometry.y() + height / 2, (width / resizeX), (height / resizeY), resizeX, resizeY);
}

void arrangeImageTaskWidgetsInGridOnMonitor(int screenIdx, int resizeX, int resizeY)
{
    arrangeWidgetsInGridOnMonitor(getImageTaskWidgets(), screenIdx, resizeX, resizeY);
}

void arrangeWidgetsInGridOnPrimaryMonitor(const std::vector<QWidget*>& widgets, int resizeX, int resizeY)
{
    arrangeWidgetsInGridOnMonitor(widgets, getPrimaryScreenIdx(), resizeX, resizeY);
}

void arrangeImageTaskWidgetsInGridOnPrimaryMonitor(int resizeX, int resizeY)
{
    arrangeWidgetsInGridOnPrimaryMonitor(getImageTaskWidgets(), resizeX, resizeY);
}

void fitWidgetsInGridOnMonitor(const std::vector<QWidget*>& widgets, int screenIdx)
{
    QList<QScreen*> screens = QGuiApplication::screens();
    if(screenIdx >= screens.size()) {
        return;
    }
    QRect screenGeometry = screens.at(screenIdx)->geometry();
    const int width = screenGeometry.width();
    const int height = screenGeometry.height();
    const double maxWidgetsAcross = 4.0;
    const int widgetWidth = std::max(1.0, (static_cast<double>(width) / maxWidgetsAcross) - 5);
    const int widgetHeight = std::max(1.0, std::min((static_cast<double>(height) / (static_cast<double>(widgets.size() / maxWidgetsAcross))) - 5, 800.0));
    arrangeWidgetsInGridOnMonitor(widgets, screenIdx, widgetWidth, widgetHeight);
}

void fitImageTaskWidgetsInGridOnMonitor(int screenIdx)
{
    fitWidgetsInGridOnMonitor(getImageTaskWidgets(), screenIdx);
}

void fitWidgetsInGridOnPrimaryMonitor(const std::vector<QWidget*>& widgets)
{
    fitWidgetsInGridOnMonitor(widgets, getPrimaryScreenIdx());
}

void fitImageTaskWidgetsInGridOnPrimaryMonitor()
{
    fitWidgetsInGridOnPrimaryMonitor(getImageTaskWidgets());
}

}

}
