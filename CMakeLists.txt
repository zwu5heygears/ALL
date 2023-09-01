cmake_minimum_required(VERSION 3.16)
project(ALL VERSION 1.0)  # 指定项目和版本号
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -pthread)
set(CMAKE_CXX_STANDARD 11)  # 设置变量值
FIND_PACKAGE(OpenCV REQUIRED)
add_executable(ALL main.cpp PID.h PID.cpp PID2.cpp PID2.h)  # 添加可生成文件的源代码文件
#add_library() # 指定生成静态库或动态库的源代码文件
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS}) # 指定链接的库文件
include_directories(${OpenCV_INCLUDE_DIRS})  # 指定头文件目录

