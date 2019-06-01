#include "clang/StaticAnalyzer/Core/CheckerRegistry.h"

#include "A7_2_4.h"

using namespace clang;
using namespace clang::ento;
using namespace ac;

extern "C" void clang_registerCheckers(CheckerRegistry &registry) {
    // registry.addChecker<CHECKER_TYPE>(
    //      "checker.identifier",
    //      "Checker Description");

    registry.addChecker<A7_2_4>(
            "autosar.A7_2_4",
            "In an enumeration, either (1) none, (2) the first or (3) all enumerators shall be initialized."
    );
}

extern "C" const char clang_analyzerAPIVersionString[] = CLANG_ANALYZER_API_VERSION_STRING;