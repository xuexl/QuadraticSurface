﻿
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(QuadraticSurface)

find_package(VTK )
if (NOT VTK_FOUND)
  message("Skipping QuadraticSurface: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif()
message (STATUS "VTK_VERSION: ${VTK_VERSION}")
if (VTK_VERSION VERSION_LESS "8.90.0")
  # old system
  include(${VTK_USE_FILE})
  add_executable(QuadraticSurface MACOSX_BUNDLE QuadraticSurface.cxx )
  target_link_libraries(QuadraticSurface PRIVATE ${VTK_LIBRARIES})
else ()
  # include all components
  add_executable(QuadraticSurface MACOSX_BUNDLE QuadraticSurface.cxx )
  target_link_libraries(QuadraticSurface PRIVATE ${VTK_LIBRARIES})
  # vtk_module_autoinit is needed
  vtk_module_autoinit(
    TARGETS QuadraticSurface
    MODULES ${VTK_LIBRARIES}
    )
endif () 
