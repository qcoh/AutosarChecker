set(CHECKER_SOURCES
        register_checkers.cpp
        report.cpp

        A7_2_2.cpp
        A7_2_3.cpp
        A7_2_4.cpp)

add_library(autosar_checker SHARED ${CHECKER_SOURCES})
target_link_libraries(autosar_checker PRIVATE
        LLVM)
