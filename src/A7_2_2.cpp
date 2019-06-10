#include "A7_2_2.h"
#include "report.h"

#include "clang/StaticAnalyzer/Core/BugReporter/BugType.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h"
#include "clang/AST/Decl.h"

using namespace clang;
using namespace clang::ento;

namespace ac {

    A7_2_2::A7_2_2() : m_bugType{
            std::make_unique<BugType>(
                    this,
                    "Enumeration underlying base type shall be explicitly defined.",
                    "Autosar A7-2-2 (required, implementation, automated)"
            )
    } {}

    A7_2_2::~A7_2_2() = default;

    void A7_2_2::checkASTDecl(const EnumDecl *enumDecl,
                              AnalysisManager &analysisManager,
                              BugReporter &bugReporter) const {
        if (!enumDecl) {
            return;
        }

        const bool isUnderlyingTypeDefined = enumDecl->getIntegerTypeSourceInfo() != nullptr;

        if (!isUnderlyingTypeDefined) {
            report(enumDecl->getBeginLoc(), analysisManager.getSourceManager(), bugReporter, *m_bugType);
        }

    }

}