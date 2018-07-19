project(LoadDisp)
add_executable(LoadDisp src/LoadDisp.cpp)

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(LoadDisp ${OpenCV_LIBRARIES})