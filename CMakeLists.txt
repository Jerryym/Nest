# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required(VERSION 3.16)

# 设置项目版本号
set(NEST_VERSION_MAJOR 0)
set(NEST_VERSION_MINOR 1)
set(NEST_VERSION_PATCH 0)
set(NEST_VERSION "${NEST_VERSION_MAJOR}.${NEST_VERSION_MINOR}.${NEST_VERSION_PATCH}")
message(STATUS "Nest Version: ${NEST_VERSION}")
project(Nest VERSION ${NEST_VERSION} LANGUAGES CXX)

# 设置编译选项
option(NEST_BUILD_EXAMPLE "Build Example" ON)

# 加载Qt库，设置最低版本为6.5.3
set(NEST_MIN_QT_VERSION 6.5.3)
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)
message(STATUS "Current Qt Version: Qt${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}.${QT_VERSION_PATCH}")
qt_standard_project_setup()

# 设置C++版本
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置编译后文件名后缀
set(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "add a postfix, usually d on windows")
set(CMAKE_RELEASE_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")
set(CMAKE_RELWITHDEBINFO_POSTFIX "rd" CACHE STRING "add a postfix, usually empty on windows")

# 设置编译类型
if(CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_BUILD_POSTFIX "${CMAKE_RELEASE_POSTFIX}")
elseif(CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
    set(CMAKE_BUILD_POSTFIX "${CMAKE_RELWITHDEBINFO_POSTFIX}")
elseif(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_BUILD_POSTFIX "${CMAKE_DEBUG_POSTFIX}")
else()
    set(CMAKE_BUILD_POSTFIX "")
endif()

# 禁用警告
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4819")
endif()

# 设置平台
set(NEST_PLATFORM "x64")

##################################
# 添加子项目
##################################
add_subdirectory(NestApp)
# add_subdirectory(NestUI)

# example
if(NEST_BUILD_EXAMPLE)
    message(STATUS "Build Example")
    add_subdirectory(example)
endif()
