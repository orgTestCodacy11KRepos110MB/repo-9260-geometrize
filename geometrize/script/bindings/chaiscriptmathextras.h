// Additional bindings for ChaiScript from: https://github.com/ChaiScript/ChaiScript_Extras
//
// Copyright 2015 Jason Turner
// Modifications 2021 Sam Twidale (https://samcodes.co.uk/)
//
// All Rights Reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//   * Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above
//     copyright notice, this list of conditions and the following
//     disclaimer in the documentation and/or other materials provided
//     with the distribution.
//   * Neither the name of Jason Turner nor the
//     name of contributors may be used to endorse or promote products derived
//     from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#include <cmath>
#include <memory>

#include <chaiscript/chaiscript.hpp>

namespace chaiscript
{

namespace extras
{

namespace math
{

// TRIG FUNCTIONS
template<typename Ret, typename Param>
ModulePtr cos(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::cos)), "cos");
    return m;
}

template<typename Ret, typename Param>
ModulePtr sin(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::sin)), "sin");
    return m;
}

template<typename Ret, typename Param>
ModulePtr tan(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::tan)), "tan");
    return m;
}

template<typename Ret, typename Param>
ModulePtr acos(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::acos)), "acos");
    return m;
}

template<typename Ret, typename Param>
ModulePtr asin(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::asin)), "asin");
    return m;
}

template<typename Ret, typename Param>
ModulePtr atan(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::atan)), "atan");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr atan2(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::atan2)), "atan2");
    return m;
}

// HYPERBOLIC FUNCTIONS
template<typename Ret, typename Param>
ModulePtr cosh(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::cosh)), "cosh");
    return m;
}

template<typename Ret, typename Param>
ModulePtr sinh(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::sinh)), "sinh");
    return m;
}

template<typename Ret, typename Param>
ModulePtr tanh(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::tanh)), "tanh");
    return m;
}

template<typename Ret, typename Param>
ModulePtr acosh(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::acosh)), "acosh");
    return m;
}

template<typename Ret, typename Param>
ModulePtr asinh(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::asinh)), "asinh");
    return m;
}

template<typename Ret, typename Param>
ModulePtr atanh(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::atanh)), "atanh");
    return m;
}

// EXPONENTIAL AND LOGARITHMIC FUNCTIONS
template<typename Ret, typename Param>
ModulePtr exp(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::exp)), "exp");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr frexp(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::frexp)), "frexp");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr ldexp(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::ldexp)), "ldexp");
    return m;
}

template<typename Ret, typename Param>
ModulePtr log(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::log)), "log");
    return m;
}

template<typename Ret, typename Param>
ModulePtr log10(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::log10)), "log10");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr modf(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::modf)), "modf");
    return m;
}
template<typename Ret, typename Param>
ModulePtr exp2(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::exp2)), "exp2");
    return m;
}

template<typename Ret, typename Param>
ModulePtr expm1(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::expm1)), "expm1");
    return m;
}

template<typename Ret, typename Param>
ModulePtr ilogb(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::ilogb)), "ilogb");
    return m;
}

template<typename Ret, typename Param>
ModulePtr log1p(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::log1p)), "log1p");
    return m;
}

template<typename Ret, typename Param>
ModulePtr log2(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::log2)), "log2");
    return m;
}

template<typename Ret, typename Param>
ModulePtr logb(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::logb)), "logb");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr scalbn(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::scalbn)), "scalbn");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr scalbln(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::scalbln)), "scalbln");
    return m;
}

// POWER FUNCTIONS
template<typename Ret, typename Param1, typename Param2>
ModulePtr pow(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::pow)), "pow");
    return m;
}

template<typename Ret, typename Param>
ModulePtr sqrt(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::sqrt)), "sqrt");
    return m;
}

template<typename Ret, typename Param>
ModulePtr cbrt(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::cbrt)), "cbrt");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr hypot(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::hypot)), "hypot");
    return m;
}

// ERROR AND GAMMA FUNCTIONS
template<typename Ret, typename Param>
ModulePtr erf(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::erf)), "erf");
    return m;
}

template<typename Ret, typename Param>
ModulePtr erfc(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::erfc)), "erfc");
    return m;
}

template<typename Ret, typename Param>
ModulePtr tgamma(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::tgamma)), "tgamma");
    return m;
}

template<typename Ret, typename Param>
ModulePtr lgamma(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::lgamma)), "lgamma");
    return m;
}

// ROUNDING AND REMAINDER FUNCTIONS
template<typename Ret, typename Param>
ModulePtr ceil(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::ceil)), "ceil");
    return m;
}

template<typename Ret, typename Param>
ModulePtr floor(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::floor)), "floor");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr fmod(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::fmod)), "fmod");
    return m;
}

template<typename Ret, typename Param>
ModulePtr trunc(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::trunc)), "trunc");
    return m;
}

template<typename Ret, typename Param>
ModulePtr round(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::round)), "round");
    return m;
}

template<typename Ret, typename Param>
ModulePtr lround(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::lround)), "lround");
    return m;
}

// long long ints do not work
template<typename Ret, typename Param>
ModulePtr llround(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::llround)), "llround");
    return m;
}

template<typename Ret, typename Param>
ModulePtr rint(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::rint)), "rint");
    return m;
}

template<typename Ret, typename Param>
ModulePtr lrint(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::lrint)), "lrint");
    return m;
}

// long long ints do not work
template<typename Ret, typename Param>
ModulePtr llrint(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::llrint)), "llrint");
    return m;
}

template<typename Ret, typename Param>
ModulePtr nearbyint(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::nearbyint)), "nearbyint");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr remainder(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::remainder)), "remainder");
    return m;
}

template<typename Ret, typename Param1, typename Param2, typename Param3>
ModulePtr remquo(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2, Param3)>(&std::remquo)), "remquo");
    return m;
}

// FLOATING-POINT MANIPULATION FUNCTIONS
template<typename Ret, typename Param1, typename Param2>
ModulePtr copysign(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::copysign)), "copysign");
    return m;
}

template<typename Ret, typename Param>
ModulePtr nan(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::nan)), "nan");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr nextafter(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::nextafter)), "nextafter");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr nexttoward(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::nexttoward)), "nexttoward");
    return m;
}

// MINIMUM, MAXIMUM, DIFFERENCE FUNCTIONS
template<typename Ret, typename Param1, typename Param2>
ModulePtr fdim(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::fdim)), "fdim");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr fmax(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::fmax)), "fmax");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr fmin(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::fmin)), "fmin");
    return m;
}

// OTHER FUNCTIONS
template<typename Ret, typename Param>
ModulePtr fabs(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::fabs)), "fabs");
    return m;
}

template<typename Ret, typename Param>
ModulePtr abs(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::abs)), "abs");
    return m;
}

template<typename Ret, typename Param1, typename Param2, typename Param3>
ModulePtr fma(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2, Param3)>(&std::fma)), "fma");
    return m;
}

// CLASSIFICATION FUNCTIONS
template<typename Ret, typename Param>
ModulePtr fpclassify(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::fpclassify)), "fpclassify");
    return m;
}

template<typename Ret, typename Param>
ModulePtr isfinite(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::isfinite)), "isfinite");
    return m;
}

template<typename Ret, typename Param>
ModulePtr isinf(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::isinf)), "isinf");
    return m;
}

template<typename Ret, typename Param>
ModulePtr isnan(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::isnan)), "isnan");
    return m;
}

template<typename Ret, typename Param>
ModulePtr isnormal(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::isnormal)), "isnormal");
    return m;
}

template<typename Ret, typename Param>
ModulePtr signbit(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param)>(&std::signbit)), "signbit");
    return m;
}

// COMPARISON FUNCTIONS
template<typename Ret, typename Param1, typename Param2>
ModulePtr isgreater(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::isgreater)), "isgreater");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr isgreaterequal(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::isgreaterequal)), "isgreaterequal");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr isless(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::isless)), "isless");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr islessequal(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::islessequal)), "islessequal");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr islessgreater(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::islessgreater)), "islessgreater");
    return m;
}

template<typename Ret, typename Param1, typename Param2>
ModulePtr isunordered(ModulePtr m = std::make_shared<Module>())
{
    m->add(chaiscript::fun(static_cast<Ret (*)(Param1, Param2)>(&std::isunordered)), "isunordered");
    return m;
}

ModulePtr bootstrap(ModulePtr m = std::make_shared<Module>())
{
    // TRIG FUNCTIONS
    cos<double, double>(m);
    cos<float, float>(m);
    cos<long double, long double>(m);

    sin<double, double>(m);
    sin<float, float>(m);
    sin<long double, long double>(m);

    tan<double, double>(m);
    tan<float, float>(m);
    tan<long double, long double>(m);

    acos<double, double>(m);
    acos<float, float>(m);
    acos<long double, long double>(m);

    asin<double, double>(m);
    asin<float, float>(m);
    asin<long double, long double>(m);

    atan<double, double>(m);
    atan<float, float>(m);
    atan<long double, long double>(m);

    atan2<double, double, double>(m);
    atan2<float, float, float>(m);
    atan2<long double, long double, long double>(m);

    // HYPERBOLIC FUNCTIONS
    cosh<double, double>(m);
    cosh<float, float>(m);
    cosh<long double, long double>(m);

    sinh<double, double>(m);
    sinh<float, float>(m);
    sinh<long double, long double>(m);

    tanh<double, double>(m);
    tanh<float, float>(m);
    tanh<long double, long double>(m);

    acosh<double, double>(m);
    acosh<float, float>(m);
    acosh<long double, long double>(m);

    asinh<double, double>(m);
    asinh<float, float>(m);
    asinh<long double, long double>(m);

    atanh<double, double>(m);
    atanh<float, float>(m);
    atanh<long double, long double>(m);

    // EXPONENTIAL AND LOGARITHMIC FUNCTIONS
    exp<double, double>(m);
    exp<float, float>(m);
    exp<long double, long double>(m);

    frexp<double, double, int *>(m);
    frexp<float, float, int *>(m);
    frexp<long double, long double, int *>(m);

    ldexp<double, double, int>(m);
    ldexp<float, float, int>(m);
    ldexp<long double, long double, int>(m);

    log<double, double>(m);
    log<float, float>(m);
    log<long double, long double>(m);

    log10<double, double>(m);
    log10<float, float>(m);
    log10<long double, long double>(m);

    modf<double, double, double *>(m);
    modf<float, float, float *>(m);
    modf<long double, long double, long double *>(m);

    exp2<double, double>(m);
    exp2<float, float>(m);
    exp2<long double, long double>(m);

    expm1<double, double>(m);
    expm1<float, float>(m);
    expm1<long double, long double>(m);

    ilogb<int, double>(m);
    ilogb<int, float>(m);
    ilogb<int, long double>(m);

    log1p<double, double>(m);
    log1p<float, float>(m);
    log1p<long double, long double>(m);

    log2<double, double>(m);
    log2<float, float>(m);
    log2<long double, long double>(m);

    logb<double, double>(m);
    logb<float, float>(m);
    logb<long double, long double>(m);

    scalbn<double, double, int>(m);
    scalbn<float, float, int>(m);
    scalbn<long double, long double, int>(m);

    scalbln<double, double, long int>(m);
    scalbln<float, float, long int>(m);
    scalbln<long double, long double, long int>(m);

    // POWER FUNCTIONS
    pow<double, double, double>(m);
    pow<float, float, float>(m);
    pow<long double, long double, long double>(m);

    sqrt<double, double>(m);
    sqrt<float, float>(m);
    sqrt<long double, long double>(m);

    cbrt<double, double>(m);
    cbrt<float, float>(m);
    cbrt<long double, long double>(m);

    hypot<double, double, double>(m);
    hypot<float, float, float>(m);
    hypot<long double, long double, long double>(m);

    // ERROR AND GAMMA FUNCTIONS
    erf<double, double>(m);
    erf<float, float>(m);
    erf<long double, long double>(m);

    erfc<double, double>(m);
    erfc<float, float>(m);
    erfc<long double, long double>(m);

    tgamma<double, double>(m);
    tgamma<float, float>(m);
    tgamma<long double, long double>(m);

    lgamma<double, double>(m);
    lgamma<float, float>(m);
    lgamma<long double, long double>(m);

    // ROUNDING AND REMAINDER FUNCTIONS
    ceil<double, double>(m);
    ceil<float, float>(m);
    ceil<long double, long double>(m);

    floor<double, double>(m);
    floor<float, float>(m);
    floor<long double, long double>(m);

    fmod<double, double, double>(m);
    fmod<float, float, float>(m);
    fmod<long double, long double, long double>(m);

    trunc<double, double>(m);
    trunc<float, float>(m);
    trunc<long double, long double>(m);

    round<double, double>(m);
    round<float, float>(m);
    round<long double, long double>(m);

    lround<long int, double>(m);
    lround<long int, float>(m);
    lround<long int, long double>(m);

    // long long ints do not work
    llround<long long int, double>(m);
    llround<long long int, float>(m);
    llround<long long int, long double>(m);

    rint<double, double>(m);
    rint<float, float>(m);
    rint<long double, long double>(m);

    lrint<long int, double>(m);
    lrint<long int, float>(m);
    lrint<long int, long double>(m);

    // long long ints do not work
    llrint<long long int, double>(m);
    llrint<long long int, float>(m);
    llrint<long long int, long double>(m);

    nearbyint<double, double>(m);
    nearbyint<float, float>(m);
    nearbyint<long double, long double>(m);

    remainder<double, double, double>(m);
    remainder<float, float, float>(m);
    remainder<long double, long double, long double>(m);

    remquo<double, double, double, int *>(m);
    remquo<float, float, float, int *>(m);
    remquo<long double, long double, long double, int *>(m);

    // FLOATING-POINT MANIPULATION FUNCTIONS
    copysign<double, double, double>(m);
    copysign<float, float, float>(m);
    copysign<long double, long double, long double>(m);

    nan<double, const char*>(m);

    nextafter<double, double, double>(m);
    nextafter<float, float, float>(m);
    nextafter<long double, long double, long double>(m);

    nexttoward<double, double, long double>(m);
    nexttoward<float, float, long double>(m);
    nexttoward<long double, long double, long double>(m);

    // MINIMUM, MAXIMUM, DIFFERENCE FUNCTIONS
    fdim<double, double, double>(m);
    fdim<float, float, float>(m);
    fdim<long double, long double, long double>(m);

    fmax<double, double, double>(m);
    fmax<float, float, float>(m);
    fmax<long double, long double, long double>(m);

    fmin<double, double, double>(m);
    fmin<float, float, float>(m);
    fmin<long double, long double, long double>(m);

    // OTHER FUNCTIONS
    fabs<double, double>(m);
    fabs<float, float>(m);
    fabs<long double, long double>(m);

    abs<double, double>(m);
    abs<float, float>(m);
    abs<long double, long double>(m);

    fma<double, double, double, double>(m);
    fma<float, float, float, float>(m);
    fma<long double, long double, long double, long double>(m);

    // CLASSIFICATION FUNCTIONS
    fpclassify<int, float>(m);
    fpclassify<int, double>(m);
    fpclassify<int, long double>(m);

    isfinite<bool, float>(m);
    isfinite<bool, double>(m);
    isfinite<bool, long double>(m);

    isinf<bool, float>(m);

    // Disabled as these won't compile with gcc6
    //isinf<bool, double>(m);
    //isinf<bool, long double>(m);

    isnan<bool, float>(m);

    // Disabled as these won't compile with gcc6
    //isnan<bool, double>(m);
    //isnan<bool, long double>(m);

    isnormal<bool, float>(m);
    isnormal<bool, double>(m);
    isnormal<bool, long double>(m);

    signbit<bool, float>(m);
    signbit<bool, double>(m);
    signbit<bool, long double>(m);

    // COMPARISON FUNCTIONS
    isgreater<bool, double, double>(m);
    isgreater<bool, float, float>(m);
    isgreater<bool, long double, long double>(m);

    isgreaterequal<bool, double, double>(m);
    isgreaterequal<bool, float, float>(m);
    isgreaterequal<bool, long double, long double>(m);

    isless<bool, double, double>(m);
    isless<bool, float, float>(m);
    isless<bool, long double, long double>(m);

    islessequal<bool, double, double>(m);
    islessequal<bool, float, float>(m);
    islessequal<bool, long double, long double>(m);

    islessgreater<bool, double, double>(m);
    islessgreater<bool, float, float>(m);
    islessgreater<bool, long double, long double>(m);

    isunordered<bool, double, double>(m);
    isunordered<bool, float, float>(m);
    isunordered<bool, long double, long double>(m);

    return m;
}

}

}

}
