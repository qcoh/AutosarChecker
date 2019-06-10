#include "A7_2_3.h"
#include "report.h"

#include "clang/StaticAnalyzer/Core/BugReporter/BugType.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h"
#include "clang/AST/Decl.h"

using namespace clang;
using namespace clang::ento;

namespace ac {

    A7_2_3::A7_2_3() : m_bugType{
            std::make_unique<BugType>(
                    this,
                    "Enumerations shall be declared as scoped enum classes.",
                    "Autosar A7-2-3 (required, implementation, automated)"
            )
    } {}

    A7_2_3::~A7_2_3() = default;

    void A7_2_3::checkASTDecl(const EnumDecl *enumDecl,
                              AnalysisManager &analysisManager,
                              BugReporter &bugReporter) const {
        if (!enumDecl) {
            return;
        }

        if (!enumDecl->isScopedUsingClassTag()) {
            report(enumDecl->getBeginLoc(), analysisManager.getSourceManager(), bugReporter, *m_bugType);
        }
    }
}