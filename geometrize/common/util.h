#pragma once

#include <cassert>
#include <string>
#include <sstream>
#include <vector>

class QWidget;

namespace geometrize
{

namespace script
{

class Command;
class CommandHandler;

}

}

namespace geometrize
{

namespace util
{

/**
 * @brief printToConsole A convenience function for printing a string to the command-line console.
 * @param str The string to print to the console.
 */
void printToConsole(const std::string& str);

/**
 * @brief printToAllScriptConsoleWidgets A convenience function for printing a string to all the GUI console widgets in the application
 * @param str The string to print to the script console widgets.
 */
void printToAllScriptConsoleWidgets(const std::string& str);

/**
 * @brief messageBox A convenience function for displaying a message box containing a message.
 * @param str The string to display in the message box.
 */
void messageBox(const std::string& str);

/**
 * @brief debugBreak Forces the debugger to break/halt the application when this is called.
 */
void debugBreak();

/**
 * @brief processApplicationEvents Processes all pending application events for the calling thread.
 */
void processApplicationEvents();

/**
 * @brief fileExists Checks if a file exists, returns true if it does.
 * @param filePath The file path.
 * @return True if the file exists, false if it does not.
 */
bool fileExists(const std::string& filePath);

/**
 * @brief directoryExists Checks if a directory exists, returns true if it does.
 * @param dirPath The directory path.
 * @return True if the directory exists, false if it does not.
 */
bool directoryExists(const std::string& dirPath);

/**
 * @brief directoriesExist Checks if the given directories exist, returns true if all do.
 * @param dirPaths The directory paths.
 * @return True if all the directories exist, false if any do not.
 */
bool directoriesExist(const std::vector<std::string>& dirPaths);

/**
 * @brief directoryContainsFile Checks if the directory contains the given file, returns true if it does.
 * @return True if the directory contains the given file, false otherwise.
 */
bool directoryContainsFile(const std::string& dirPath, const std::string& fileName);

/**
 * @brief createDirectory Creates the directory at the given path, recursively creating subdirectories if needed
 * @return True if the directory was created (or already existed), else false
 */
bool createDirectory(const std::string& dirPath);

/**
 * @brief readFileAsString Reads a file, returning a string containing the contents.
 * @param filePath The path to the file.
 * @return The contents of the file, as a string.
 */
std::string readFileAsString(const std::string& filePath);

/**
 * @brief getFilePathsForDirectory Gets the absolute file paths to the files in the given directory.
 * @param dirPath The directory to search.
 * @return A vector of files.
 */
std::vector<std::string> getFilePathsForDirectory(const std::string& dirPath);

/**
 * @brief getSubdirectoriesForDirectory Gets the absolute paths for direct subdirectories of the given directory.
 * @param dirPath The directory to search.
 * @return A vector of directory paths.
 */
std::vector<std::string> getSubdirectoriesForDirectory(const std::string& dirPath);

/**
 * @brief getFilesWithExtension Gets the absolute file paths to the files with the given extension in the given directory.
 * @param dirPath The directory to search.
 * @param extension The file extension to match.
 * @return The file paths to the files encountered, empty vector if there are no matching files. The order of the file paths is implementation-dependent.
 */
std::vector<std::string> getFilesWithExtension(const std::string& dirPath, const std::string& extension);

/**
 * @brief getFirstFileWithExtension Gets the absolute file path to the first file with the given extension in the given directory.
 * @param dirPath The directory to search.
 * @param extension The file extension to match.
 * @return The file path to the first matching file encountered, empty string if there are no matching files. The 'first' file is implementation-dependent.
 */
std::string getFirstFileWithExtension(const std::string& dirPath, const std::string& extension);

/**
 * @brief getFirstFileWithExtensions Gets the absolute file path to the first file with one of the given extensions in the given directory.
 * @param dirPath The directory to search.
 * @param extensions The file extension to match.
 * @return The file path to the first matching file encountered, empty string if there are no matching files. The 'first' file is implementation-dependent.
 */
std::string getFirstFileWithExtensions(const std::string& dirPath, const std::vector<std::string>& extensions);

/**
 * @brief getScriptsForPath Gets the absolute file paths to the script files (*.chai) for the given directory, using recursive search.
 * @param dirPath The directory to search.
 * @return The absolute file paths to the script files for the given directory.
 */
std::vector<std::string> getScriptsForPath(const std::string& path);

/**
 * @brief getScriptsForPaths Gets the absolute file paths to the script files (*.chai) for the given directories, using recursive search.
 * @param dirPaths The directories to search.
 * @return The absolute file paths to the script files for the given directories.
 */
std::vector<std::string> getScriptsForPaths(const std::vector<std::string>& dirPaths);

/**
 * @brief getDirectoryForFilePath Gets the directory path from the given local file path.
 * @param filePath The filepath to chop.
 * @return The directory path i.e. the file path with the file name and any trailing slashes removed.
 */
std::string getDirectoryForFilePath(const std::string& filePath);

/**
 * @brief getFileNameForFilePath Gets the filename from the given local file path.
 * @param filePath The filepath to chop.
 * @return The filename i.e. the file name from the end of the filepath
 */
std::string getFileNameForFilePath(const std::string& filePath);

/**
 * @brief openInDefaultApplication Opens the given path in the default application.
 * @param path The path to the resource to open.
 * @return True if the directory, file, URL (or whatever) should open, else false.
 */
bool openInDefaultApplication(const std::string& path);

/**
 * @brief revealInDefaultApplication Reveals the given path in the parent folder (or path with the filename trimmed).
 * @param path The path to the resource to view.
 * @return True if the file, folder, URL (or whatever) should be revealed, else false.
 */
bool revealInDefaultApplication(const std::string& path);

/**
 * @brief clearGlobalClipboard Clears the global system clipboard contents.
 */
void clearGlobalClipboard();

/**
 * @brief getGlobalClipboardText Gets the global system clipboard text.
 * @return The global system clipboard text, or an empty string if the clipboard does not contain any text.
 */
std::string getGlobalClipboardText();

/**
 * @brief setClipboardText Sets the global system clipboard text.
 * @param text The text to set as the clipboard text.
 */
void setGlobalClipboardText(const std::string& text);

/**
 * @brief stringBeginsWith Checks if a string begins with the given prefix.
 * @param str The string to check.
 * @param prefix The prefix to check for.
 * @return True if the string begins with the given prefix, false otherwise.
 */
bool stringBeginsWith(const std::string& str, const std::string& prefix);

/**
 * @brief stringEndsWith Checks if a string ends with the given suffix.
 * @param str The string to check.
 * @param suffix The suffix ending to check for.
 * @return True if the string ends with the given suffix, false otherwise.
 */
bool stringEndsWith(const std::string& str, const std::string& suffix);

/**
 * @brief getApplicationDirectory Get directory that the application is in.
 * @return Get application directory.
 */
std::string getApplicationDirectoryLocation();

/**
 * @brief getAppDataLocation Returns a directory location where persistent application data can be stored.
 * @return Directory location where persistent application data can be stored.
 */
std::string getAppDataLocation();

/**
 * @brief getHomeDirectoryLocation Returns a path to where the user's home directory is.
 * @return Location of the user's home directory.
 */
std::string getHomeDirectoryLocation();

/**
 * @brief getDesktopDirectoryLocation Returns a path to where the user's desktop is.
 * @return Location of the user's desktop directory.
 */
std::string getDesktopDirectoryLocation();

/**
 * @brief writeStringToFile Writes the string to the file path, attempting to overwrite any existing file at the path.
 * @param str The string to write to file.
 * @param path The file path to write to.
 * @return True if the string was successfully written to the file, else false.
 */
bool writeStringToFile(const std::string& str, const std::string& path);

/**
 * @brief percentEncode Returns a percent-encoded copy of the input string.
 * @param str The input string, to be percent-encoded.
 * @return The percent-encoded input string.
 */
std::string percentEncode(const std::string& str);

/**
 * @brief randomInRange Returns a random integer in the range [lower, upper], inclusive. Note that this uses thread-local RNGs under the hood.
 * This must not be called on the same thread as the Geometrize shape mutation code - otherwise the shape generation may not be deterministic.
 * @param lower The minimum value.
 * @param upper The maximum value.
 * @return An integer in the range [lower, upper] inclusive.
 */
int randomInRange(int lower, int upper);

/**
 * @brief clamp Clamps a value within a range.
 * @param value The value to clamp.
 * @param lower The lower bound of the range.
 * @param upper The upper bound of the range.
 * @return The clamped value.
 */
template<typename T>
T clamp(T value, T lower, T upper)
{
    assert(lower <= upper);
    if (value < lower) {
        value = lower;
    }
    if (value > upper) {
        value = upper;
    }
    return value;
}

template<typename T>
void split(const std::string& s, const char delimiter, T result)
{
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        *(result++) = item;
    }
}

/**
 * @brief split Splits a given string into a vector of tokens using the given delimiter.
 * @param s The string to split.
 * @param delimiter The delimiter to split on.
 * @return A vector containing the split string.
 */
std::vector<std::string> split(const std::string& s, char delimiter);

/**
 * @brief getCursorX Gets the x-coordinate of the cursor in global screen coordinates.
 * @return The x-coordinate of the cursor.
 */
int getCursorX();

/**
 * @brief getCursorY Gets the y-coordinate of the cursor in global screen coordinates.
 * @return The y-coordinate of the cursor.
 */
int getCursorY();

/**
 * @brief setCursorPos Sets the cursor position in global screen coordinates.
 * @param x The x-coordinate of the cursor.
 * @param y The y-coordinate of the cursor.
 */
void setCursorPos(int x, int y);

/**
 * @brief getOperatingSystemProductType Returns the product name of the operating system this application is running in.
 * @return The name of the operating system: "windows", "osx", "linux", "android", "ios", "tvos" etc
 */
std::string getOperatingSystemProductType();

/**
 * @brief saveWidgetScreenshot Takes a screenshot of the given widget and saves it as a .png image to the given path.
 * @param path The file path to save the screenshot to.
 * @param widget The widget to take a screenshot of.
 * @return True if the screenshot was taken and save successfully, else false.
 */
bool saveWidgetScreenshot(const std::string& path, QWidget* widget);

/**
 * @brief getAllWidgetNames Returns a vector containing the names of all the existing widgets in the application
 * @return A vector containing the names of all the existing widgets in the application
 */
std::vector<std::string> getAllNamedWidgets();

/**
 * @brief getAllWidgetNames Returns a vector containing the names of all the widgets in the application with "geometrize" in their name
 * @return A vector containing the names of all the existing widgets in the application with "geometrize" in their name
 */
std::vector<std::string> getAllNamedGeometrizeWidgets();

/**
 * @brief getWidgetByName Returns the first found instance of the existing widget with the given name
 * @param widgetName The name of the widget to find
 * @return A pointer to the first widget instance with the given name, nullptr if no match
 */
QWidget* getWidgetByName(const std::string& widgetName);

/**
 * @brief getAllNamedCommandHandlers Gets all of the existing objects in the application that implement the CommandHandler interface and can be addressed by name
 * @return A vector containing the names of all existing objects that implement the CommandHandler interface
 */
std::vector<std::string> getAllNamedCommandHandlers();

/**
 * @brief getCommandHandlerByName Returns the first found instance of the existing command handler with the given name
 * @param name The name of the command handler to find
 * @return A pointer to the first command handler with the given name, nullptr if no match
 */
geometrize::script::CommandHandler* getCommandHandlerByName(const std::string& name);

/**
 * @brief sendCommand Sends a command to the given command handler
 * @param target The name of the target command handler
 * @param command A string representation of the command
 */
void sendCommand(const std::string& target, const std::string& command);

/**
 * @brief sendCommand Sends a command to the given command handler
 * @param target The name of the target command handler
 * @param command A command object representing the command
 */
void sendCommand(const std::string& target, geometrize::script::Command& command);

/**
 * @brief broadcastCommand Sends a command to all command handlers
 * @param command A string representation of the command
 */
void broadcastCommand(const std::string& command);

/**
 * @brief broadcastCommand Sends a command to all command handlers
 * @param command A command object representing the command
 */
void broadcastCommand(geometrize::script::Command& command);

/**
 * @brief getFormattedTimestamp Gets a formatted timestamp for the current local time
 * @param formatString The format of the timestamp e.g. "ddMMyyyy-hhmmss"
 * @return A string representing a timestamp for the current local time
 */
std::string getFormattedTimestamp(const std::string& formatString);

/**
 * @brief getFilenameTimestamp Gets a filename timestamp string for the current local time
 * @return A timestamp string in the format "yyyy_MM_dd_hh_mm_ss_zzz"
 */
std::string getFilenameTimestamp();

/**
 * @brief getUuidString Gets a Universally Unique Identifier (UUID) as a string
 * @return The UUID string
 */
std::string getUuidString();

/**
 * @brief setWidgetSize Sets the size of the given widget in pixels.
 * @param widget The widget to resize.
 * @param width The width to set on the widget.
 * @param height The height to set on the widget.
 */
void setWidgetSize(QWidget* widget, int width, int height);

/**
 * @brief setWidgetPosition Sets the widget to the given position.
 * @param widget The widget to move.
 * @param x The x-coordinate to set on the widget.
 * @param y The y-coordinate to set on the widget.
 */
void setWidgetPosition(QWidget* widget, int x, int y);

/**
 * @brief arrangeWidgetsInGrid Arranges the given widgets into a grid shape
 * @param widgets The widgets to arrange
 * @param centerX The x coordinate of where to center the grid
 * @param centerY The y coordinate of where to center the grid
 * @param xDim The number of widgets to lay out horizontally
 * @param yDim The number of widgets to lay out vertically
 * @param resizeX The width to resize the widgets to
 * @param resizeY The height to resize the widgets to
 */
void arrangeWidgetsInGrid(const std::vector<QWidget*>& widgets, int centerX, int centerY, int xDim, int yDim, int resizeX, int resizeY);

/**
 * @brief arrangeImageTaskWidgetsInGrid Arranges all the open image task widgets into a grid shape
 * @param centerX The x coordinate of where to center the grid
 * @param centerY The y coordinate of where to center the grid
 * @param xDim The number of widgets to lay out horizontally
 * @param yDim The number of widgets to lay out vertically
 * @param resizeX The width to resize the widgets to
 * @param resizeY The height to resize the widgets to
 */
void arrangeImageTaskWidgetsInGrid(int centerX, int centerY, int xDim, int yDim, int resizeX, int resizeY);

/**
 * @brief arrangeWidgetsInGridOnMonitor Arranges the given widgets into a grid on the given monitor
 * @param widgets The widgets to arrange
 * @param screenIdx The index of the screen to center the grid on
 * @param resizeX The width to resize the widgets to
 * @param resizeY The height to resize the widgets to
 */
void arrangeWidgetsInGridOnMonitor(const std::vector<QWidget*>& widgets, int screenIdx, int resizeX, int resizeY);

/**
 * @brief arrangeImageTaskWidgetsInGridOnMonitor Arranges all the open image task widgets into a grid on the given monitor
 * @param screenIdx The index of the screen to center the grid on
 * @param resizeX The width to resize the widgets to
 * @param resizeY The height to resize the widgets to
 */
void arrangeImageTaskWidgetsInGridOnMonitor(int screenIdx, int resizeX, int resizeY);

/**
 * @brief arrangeWidgetsInGridOnPrimaryMonitor Arranges the given widgets into a grid on the primary monitor
 * @param widgets The widgets to arrange
 * @param resizeX The width to resize the widgets to
 * @param resizeY The height to resize the widgets to
 */
void arrangeWidgetsInGridOnPrimaryMonitor(const std::vector<QWidget*>& widgets, int resizeX, int resizeY);

/**
 * @brief arrangeImageTaskWidgetsInGridOnPrimaryMonitor Arranges all the open image task widgets into a grid on the given monitor
 * @param resizeX The width to resize the widgets to
 * @param resizeY The height to resize the widgets to
 */
void arrangeImageTaskWidgetsInGridOnPrimaryMonitor(int resizeX, int resizeY);

/**
 * @brief fitWidgetsInGridOnMonitor Fits the given widgets into a grid on the given monitor
 * @param widgets The widgets to arrange
 * @param screenIdx The index of the screen to center the grid on
 */
void fitWidgetsInGridOnMonitor(const std::vector<QWidget*>& widgets, int screenIdx);

/**
 * @brief fitImageTaskWidgetsInGridOnMonitor Fits all of the open image task widgets into a grid on the given monitor
 * @param screenIdx The index of the screen to center the grid on
 */
void fitImageTaskWidgetsInGridOnMonitor(int screenIdx);

/**
 * @brief fitWidgetsInGridOnPrimaryMonitor Fits the given widgets into a grid on the primary monitor
 * @param widgets The widgets to arrange
 */
void fitWidgetsInGridOnPrimaryMonitor(const std::vector<QWidget*>& widgets);

/**
 * @brief fitImageTaskWidgetsInGridOnPrimaryMonitor Fits all of the open image task widgets into a grid on the primary monitor
 */
void fitImageTaskWidgetsInGridOnPrimaryMonitor();

}

}
