#include "A7_2_4.h"
#include "report.h"

#include <memory>

#include "clang/StaticAnalyzer/Core/BugReporter/BugType.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h"
#include "clang/AST/Decl.h"

using namespace clang;
using namespace clang::ento;

namespace ac {

    A7_2_4::A7_2_4() : m_bugType{
            std::make_unique<BugType>(
                    this,
                    "In an enumeration, either (1) none, (2) the first or (3) all enumerators shall be initialized.",
                    "Autosar (required, implementation, automated)"
            )
    } {}

    A7_2_4::~A7_2_4() = default;

    void A7_2_4::checkASTDecl(const EnumDecl *enumDecl,
                              AnalysisManager &analysisManager,
                              BugReporter &bugReporter) const {

        if (!enumDecl) {
            return;
        }

        State s = State::Initial;

        for (const auto &enumerator : enumDecl->enumerators()) {
            const bool isEnumeratorInitialized = enumerator->getInitExpr() != nullptr;

            switch (s) {
                case State::Initial:
                    s = isEnumeratorInitialized ? State::FirstEnumeratorInitialized
                                                : State::ExpectRemainingEnumeratorsUninitialized;
                    break;
                case State::FirstEnumeratorInitialized:
                    s = isEnumeratorInitialized ? State::ExpectRemainingEnumeratorsInitialized
                                                : State::ExpectRemainingEnumeratorsUninitialized;
                    break;
                case State::ExpectRemainingEnumeratorsInitialized:
                    if (!isEnumeratorInitialized) {
                        report(enumerator->getBeginLoc(), analysisManager.getSourceManager(), bugReporter,
                               *m_bugType);
                    }
                    break;
                case State::ExpectRemainingEnumeratorsUninitialized:
                    if (isEnumeratorInitialized) {
                        report(enumerator->getBeginLoc(), analysisManager.getSourceManager(), bugReporter,
                               *m_bugType);

                    }
                    break;
            }
        }
    }
}