cmake_minimum_required(VERSION 3.5)

project(quadratic LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(VTK )

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB UI_FILES *.ui)
file(GLOB QT_WRAP *.h)
file(GLOB CXX_FILES *.cxx)

qt5_wrap_ui(UISrcs ${UI_FILES})


add_executable(quadratic
main.cpp
mainwindow.cpp
mainwindow.h
mainwindow.ui
)

target_link_libraries(quadratic PRIVATE Qt5::Widgets)

# CMAKE_AUTOMOC in ON so the MOC headers will be automatically wrapped.
add_executable(BorderWidgetQt MACOSX_BUNDLE
  ${CXX_FILES} ${UISrcs} ${QT_WRAP})
qt5_use_modules(BorderWidgetQt Core Gui)
target_link_libraries(BorderWidgetQt ${VTK_LIBRARIES})
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS BorderWidgetQt
  MODULES ${VTK_LIBRARIES}
)
