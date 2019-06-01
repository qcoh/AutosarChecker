#include "report.h"

#include "clang/StaticAnalyzer/Core/BugReporter/BugType.h"
#include "clang/StaticAnalyzer/Core/BugReporter/BugReporter.h"
#include "clang/StaticAnalyzer/Core/BugReporter/PathDiagnostic.h"

using namespace clang;
using namespace clang::ento;

namespace ac {

    void report(const SourceLocation &sourceLocation,
                SourceManager &sourceManager,
                BugReporter &bugReporter,
                BugType &bugType) {
        PathDiagnosticLocation pathDiagnosticLocation{sourceLocation, sourceManager};
        bugReporter.emitReport(
                std::make_unique<BugReport>(bugType, bugType.getName(), pathDiagnosticLocation));
    }
}