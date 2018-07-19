project(Gray)
add_executable(Gray src/Gray.cpp)

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Gray ${OpenCV_LIBRARIES})