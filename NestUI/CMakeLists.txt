# CMakeList.txt: NestUI 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required(VERSION 3.16)

project(NestUI VERSION ${NEST_VERSION} LANGUAGES CXX)
set(NESTUI_LIB_NAME NestUI)
message(STATUS "NESTUI_LIB_NAME: ${NESTUI_LIB_NAME}")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 定义头列表
set(NESTUI_HEADERS
	src/Base.h
	src/GUI/MainWindow.h
	src/GUI/DockWidget.h
	src/Core/DockWidgetManager.h
	src/NestUI.h
)

# 定义源文件列表
set(NESTUI_SOURCES
	src/GUI/MainWindow.cpp
	src/GUI/DockWidget.cpp
	src/Core/DockWidgetManager.cpp
)

# 创建一个共享库
add_library(${NESTUI_LIB_NAME} SHARED
    ${NESTUI_SOURCES}
    ${NESTUI_HEADERS}
)

# 预编译头文件
target_precompile_headers(${NESTUI_LIB_NAME} PRIVATE src/nestuipch.h)

# 添加头文件
target_include_directories(${NESTUI_LIB_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/vendor/SARibbon/src
)

# 添加SARibbon
add_subdirectory(vendor/SARibbon)
set(SARibbonBar_DIR ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Debug-windows-x86_64/NestUI)
target_link_libraries(${NESTUI_LIB_NAME} PRIVATE SARibbonBar::SARibbonBar)

#################################################
# Qt相关的依赖
#################################################
target_link_libraries(${NESTUI_LIB_NAME} PUBLIC 
	Qt${QT_VERSION_MAJOR}::Core
	Qt${QT_VERSION_MAJOR}::Gui
	Qt${QT_VERSION_MAJOR}::Widgets
)
message(STATUS "Link ${NESTUI_LIB_NAME} PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets")

# 预处理宏定义
target_compile_definitions(${NESTUI_LIB_NAME} PRIVATE NESTUI_BUILD_DLL)
message(STATUS "macros predefined: #define NESTUI_BUILD_DLL")

# 设置目标属性
include(GNUInstallDirs)
set_target_properties(${NESTUI_LIB_NAME} PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
    CXX_EXTENSIONS OFF
    DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
    VERSION ${NEST_VERSION}
    EXPORT_NAME ${NESTUI_LIB_NAME} 

    # Debug
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Debug-windows-x86_64/NestUI
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Debug-windows-x86_64/NestUI
    LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Debug-windows-x86_64/NestUI

    # Release
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Release-windows-x86_64/NestUI
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Release-windows-x86_64/NestUI
    LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Release-windows-x86_64/NestUI
)

# 设置Visual Studio的文件树结构
file(GLOB Base_SRC "src/*.h" "src/*.cpp")
file(GLOB GUI_SRC "src/GUI/*.h" "src/GUI/*.cpp")
source_group("src" FILES ${Base_SRC})
source_group("src\\GUI" FILES ${GUI_SRC})
