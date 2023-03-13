cmake_minimum_required (VERSION 3.0)
project(CmakeTest)
# file(GLOB SRC_FILE *.cpp)
# find_library(scip_static NAMES scip PATHS "lib/")
set(CMAKE_BUILD_TYPE "Debug")

include_directories(
        # public
)

add_executable(moving_charactor
    main.cpp
)

# target_link_libraries(runTests "D:/develop/kjmode_2/kjmode_2_qt_new/kjmode_2_qt/lib/libscip.lib")