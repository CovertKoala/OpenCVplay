set(NAME "PixelOps")

project(${NAME})
add_executable(${NAME} src/${NAME}.cpp)

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${NAME} ${OpenCV_LIBRARIES})
