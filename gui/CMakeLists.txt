# Copy some cache to this directory
# Configure: "cmake -A win32 -DCMAKE_BUILD_TYPE=Debug .."
# Build: cmake --build . --config Debug
# Run: Add to path using something like
# PATH=%PATH%;C:\Users\%USERNAME%\src\minimal\cache\wxWidgets-3.2.1\lib\vc14x_dll
#
project(example)
cmake_minimum_required(VERSION 3.12.0)
add_executable(MINIMAL WIN32 "minimal.cpp")

set(wxWidgets_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR}/../cache/wxWidgets-3.2.1)
set(wxWidgets_LIB_DIR  ${CMAKE_CURRENT_LIST_DIR}/../cache/wxWidgets-3.2.1/lib/vc14x_dll)
find_package(wxWidgets  REQUIRED  base core net xml html adv stc aui)
include(${wxWidgets_USE_FILE})
target_link_libraries(MINIMAL PUBLIC ${wxWidgets_LIBRARIES})
