cmake_minimum_required(VERSION 3.16)

set(EXAMPLE_VERSION 0.1.0)
project(example VERSION ${EXAMPLE_VERSION} LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# 加载Qt库，设置最低版本为6.5.3
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} 6.5.3 COMPONENTS Core Widgets)
message(STATUS "Current Qt Version: Qt${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}.${QT_VERSION_PATCH}")
qt_standard_project_setup()

add_executable(example 
    src/MainWindow.h
	src/MainWindow.cpp
    src/main.cpp
)

if(NOT TARGET NestApp)
    # 说明这个例子是单独加载
    message(STATUS "NOT TARGET NestApp find_package(NestApp REQUIRED)")
    find_package(NestApp REQUIRED)
endif()
target_link_libraries(example PUBLIC NestApp)
target_link_libraries(example PUBLIC NestUI)
target_link_libraries(example PUBLIC
    Qt${QT_VERSION_MAJOR}::Core 
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)

set_target_properties(example PROPERTIES
    AUTOMOC ON
    AUTORCC ON
    AUTOUIC ON
    CXX_EXTENSIONS OFF
    DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
    VERSION ${EXAMPLE_VERSION}
    EXPORT_NAME NestAppExample
    
    # Debug
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Debug-windows-x86_64/example
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Debug-windows-x86_64/example
    LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Debug-windows-x86_64/example

    # Release
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Release-windows-x86_64/example
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Release-windows-x86_64/example
    LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Release-windows-x86_64/example
)

# 设置生成后事件
add_custom_command(
    TARGET example POST_BUILD

    # 复制NestApp的DLL文件到相应的文件夹
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:NestApp> # 获取生成的 DLL 文件
    $<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/bin/Debug-windows-x86_64/example/NestAppd.dll,${CMAKE_BINARY_DIR}/bin/Release-windows-x86_64/example/NestApp.dll>

	# 复制SARibbon的DLL文件到相应的文件夹
	COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:SARibbonBar> # 获取生成的 DLL 文件
    $<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/bin/Debug-windows-x86_64/example/SARibbonBard.dll,${CMAKE_BINARY_DIR}/bin/Release-windows-x86_64/example/SARibbonBar.dll>

    # 复制NestUI的DLL文件到相应的文件夹
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:NestUI> # 获取生成的 DLL 文件
    $<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/bin/Debug-windows-x86_64/example/NestUId.dll,${CMAKE_BINARY_DIR}/bin/Release-windows-x86_64/example/NestUI.dll>

    VERBATIM
)
