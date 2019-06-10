#include "clang/StaticAnalyzer/Core/CheckerRegistry.h"

#include "A7_2_2.h"
#include "A7_2_3.h"
#include "A7_2_4.h"

using namespace clang;
using namespace clang::ento;
using namespace ac;

extern "C" void clang_registerCheckers(CheckerRegistry &registry) {
    // registry.addChecker<CHECKER_TYPE>(
    //      "checker.identifier",
    //      "Checker Description");

    registry.addChecker<A7_2_2>(
            "autosar.A7_2_2",
            "Enumeration underlying base type shall be explicitly defined."
    );

    registry.addChecker<A7_2_3>(
            "autosar.A7_2_3",
            "Enumerations shall be declared as scoped enum classes."
    );

    registry.addChecker<A7_2_4>(
            "autosar.A7_2_4",
            "In an enumeration, either (1) none, (2) the first or (3) all enumerators shall be initialized."
    );
}

extern "C" const char clang_analyzerAPIVersionString[] = CLANG_ANALYZER_API_VERSION_STRING;