#pragma once

#include <memory>

#include "clang/StaticAnalyzer/Core/Checker.h"

namespace clang::ento {
    class BugType;
}

namespace ac {

    class A7_2_2 : public clang::ento::Checker<clang::ento::check::ASTDecl<clang::EnumDecl>> {
    private:
        std::unique_ptr<clang::ento::BugType> m_bugType;

    public:
        A7_2_2();
        ~A7_2_2();

        void checkASTDecl(const clang::EnumDecl *, clang::ento::AnalysisManager &, clang::ento::BugReporter &) const;

    };

}