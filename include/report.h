#pragma once

namespace clang {
    class SourceLocation;
    class SourceManager;
}

namespace clang::ento {
    class BugReporter;
    class BugType;
}

namespace ac {
    void report(const clang::SourceLocation&, clang::SourceManager&, clang::ento::BugReporter&, clang::ento::BugType&);
}