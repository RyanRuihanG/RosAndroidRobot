cmake_minimum_required(VERSION 2.8.3)
project(face_detect)
aux_source_directory(./src SRC_LIST)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
  cv_bridge
  image_transport
  geometry_msgs
)
find_package(Qt4)
find_package(Qt4)

catkin_package()
find_package(OpenCV)
include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-2.0)
# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${GTK3_INCLUDE_DIRS})
message(staus "GTK3_INCLUDE_DIRS = ${GTK3_INCLUDE_DIRS}")
link_directories(${GTK3_LIBRARY_DIRS})
message(status " GTK3_LIBRARY_DIRS = ${GTK3_LIBRARY_DIRS}")
# Add other flags to the compiler
add_definitions(${GTK3_CFLAGS_OTHER})

include_directories(include ${catkin_INCLUDE_DIRS} ${GTK3_INCLUDE_DIRS} )
add_executable(facedetect ${SRC_LIST})
target_link_libraries(facedetect ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} ${GTK3_LIBRARIES})
add_dependencies(facedetect facedetect_generate_messages_cpp)
