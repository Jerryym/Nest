# CMakeList.txt: NestApp 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required(VERSION 3.16)

project(NestApp VERSION ${NEST_VERSION} LANGUAGES CXX)
set(NESTAPP_LIB_NAME NestApp)
message(STATUS "NESTAPP_LIB_NAME: ${NESTAPP_LIB_NAME}")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 定义头列表
set(NESTAPP_HEADERS
    src/Core.h
    src/Core/Application.h
    src/Utils/Log.h
    src/NestApp.h
)

# 定义源文件列表
set(NESTAPP_SOURCES
    src/Core/Application.cpp
    src/Utils/Log.cpp
)

# 创建一个共享库
add_library(${NESTAPP_LIB_NAME} SHARED
    ${NESTAPP_SOURCES}
    ${NESTAPP_HEADERS}
)

# 预编译头文件
target_precompile_headers(${NESTAPP_LIB_NAME} PRIVATE src/nestpch.h)

# 添加头文件
target_include_directories(${NESTAPP_LIB_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/vendor/spdlog/include
)

# ################################################
# Qt相关的依赖
# ################################################
target_link_libraries(${NESTAPP_LIB_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
)
message(STATUS "Link ${NESTAPP_LIB_NAME} PUBLIC Qt6::Core Qt6::Widgets")

# 预处理宏定义
target_compile_definitions(${NESTAPP_LIB_NAME} PRIVATE NESTAPP_BUILD_DLL)
message(STATUS "macros predefined: #define NESTAPP_BUILD_DLL")

# 设置目标属性
include(GNUInstallDirs)
set_target_properties(${NESTAPP_LIB_NAME} PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
    CXX_EXTENSIONS OFF
    DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
    VERSION ${NEST_VERSION}
    EXPORT_NAME ${NESTAPP_LIB_NAME}

    # Debug
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Debug-windows-x86_64/NestApp
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Debug-windows-x86_64/NestApp
    LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Debug-windows-x86_64/NestApp

    # Release
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Release-windows-x86_64/NestApp
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Release-windows-x86_64/NestApp
    LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Release-windows-x86_64/NestApp
)

# 设置Visual Studio的文件树结构
file(GLOB Base_SRC "src/*.h" "src/*.cpp")
file(GLOB Core_SRC "src/Core/*.h" "src/Core/*.cpp")
file(GLOB Utils_SRC "src/Utils/*.h" "src/Utils/*.cpp")
source_group("src" FILES ${Base_SRC})
source_group("src\\Core" FILES ${Core_SRC})
source_group("src\\Utils" FILES ${Utils_SRC})

# 设置生成后事件
add_custom_command(
    TARGET ${NESTAPP_LIB_NAME} POST_BUILD

    # 创建 Debug 或 Release 的目标文件夹
    COMMAND ${CMAKE_COMMAND} -E make_directory
    $<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/bin/Debug-windows-x86_64/Nest,${CMAKE_BINARY_DIR}/bin/Release-windows-x86_64/Nest>

    # 复制 DLL 文件到相应的文件夹
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:${NESTAPP_LIB_NAME}> # 获取生成的 DLL 文件
    $<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/bin/Debug-windows-x86_64/Nest/NestAppd.dll,${CMAKE_BINARY_DIR}/bin/Release-windows-x86_64/Nest/NestApp.dll>

    COMMENT "Copying NestApp DLL to Nest folder"
    VERBATIM
)
