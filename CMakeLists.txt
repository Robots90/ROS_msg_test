cmake_minimum_required(VERSION 3.0.2)
project(test_proj)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS roscpp rospy message_generation std_msgs geometry_msgs)

add_message_files(
  FILES
  Test.msg
)

#generate_messages必须在catkin_package前面
generate_messages(
 DEPENDENCIES
 geometry_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES test_msgs
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
CATKIN_DEPENDS message_runtime
)
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(test_proj src/test.cpp)

target_link_libraries(test_proj ${catkin_LIBRARIES})

add_dependencies(test_proj test_proj_gencpp)
