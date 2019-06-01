set(CHECKER_SOURCES
        register_checkers.cpp
        A7_2_4.cpp
        report.cpp
        )

add_library(autosar_checker SHARED ${CHECKER_SOURCES})
target_link_libraries(autosar_checker PRIVATE
        LLVM)
