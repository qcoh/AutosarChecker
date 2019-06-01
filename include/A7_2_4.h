#pragma once

#include "clang/StaticAnalyzer/Core/Checker.h"
#include "clang/StaticAnalyzer/Core/BugReporter/BugType.h"

namespace clang::ento {
    class BugType;
}

namespace ac {

    class A7_2_4 : public clang::ento::Checker<clang::ento::check::ASTDecl<clang::EnumDecl>> {
    private:
        std::unique_ptr<clang::ento::BugType> m_bugType;

        enum class State {
            Initial,
            FirstEnumeratorInitialized,
            ExpectRemainingEnumeratorsInitialized,
            ExpectRemainingEnumeratorsUninitialized,
        };

    public:
        A7_2_4();

        void checkASTDecl(const clang::EnumDecl *enumDecl,
                          clang::ento::AnalysisManager &analysisManager,
                          clang::ento::BugReporter &bugReporter) const;
    };
}