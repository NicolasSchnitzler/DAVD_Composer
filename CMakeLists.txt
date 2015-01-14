### CMakeLists.txt ---
##
## Author: Thibaud Kloczko
## Copyright (C) 2008 - Thibaud Kloczko, Inria.
## Created: Fri May 28 13:36:41 2010 (+0200)
######################################################################

cmake_minimum_required(VERSION 2.8.10)

######################################################################

project(davd)

## ###################################################################
## Version setup
## ###################################################################

if(${CMAKE_MAJOR_VERSION} GREATER 2)
  cmake_policy(SET CMP0042 OLD)
  cmake_policy(SET CMP0048 OLD)
endif(${CMAKE_MAJOR_VERSION} GREATER 2)


set(${PROJECT_NAME}_VERSION_MAJOR 0 CACHE STRING "numesis major version number." FORCE)
set(${PROJECT_NAME}_VERSION_MINOR 9 CACHE STRING "numesis minor version number." FORCE)
set(${PROJECT_NAME}_VERSION_BUILD 1 CACHE STRING "numesis build version number." FORCE)
set(${PROJECT_NAME}_VERSION
  "${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_BUILD}")

## ###################################################################
## Path setup
## ###################################################################

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

## #################################################################
## Install prefix
## #################################################################

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install" CACHE PATH "${PROJECT_NAME} install prefix" FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

## ###################################################################
## Build setup
## ###################################################################

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(GNUInstallDirs)
include(GenerateExportHeader)

if(APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -I/usr/lib/c++/v1")
endif(APPLE)

if(NOT APPLE AND NOT MSVC)
  include(CheckCXXCompilerFlag)
  CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
  CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
  if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-unknown-pragmas")
  elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wno-unknown-pragmas")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unknown-pragmas")
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
  endif()
else(NOT APPLE AND NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif(NOT APPLE AND NOT MSVC)


## ###################################################################
## Test setup
## ###################################################################

enable_testing()

## ###################################################################
## Options
## ###################################################################

option(BUILD_SHARED_LIBS   "Build shared libraries" true)

## #################################################################
## Dependencies
## #################################################################

find_package(Qt5Core REQUIRED)
find_package(Qt5Concurrent REQUIRED)
find_package(Qt5Declarative REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5Widgets REQUIRED)

find_package(dtk REQUIRED)
message("directories included:" ${dtk_INCLUDE_DIRS})
include_directories(${dtk_INCLUDE_DIRS})



## #################################################################
## Input
## #################################################################

set(${PROJECT_NAME}_HEADERS
    davdcomposernodefactory.h 
    Image.h 
    SegmentationProcess_p.h 
    SegmentationProcess.h 
    FilterProcess_p.h 
    FilterProcess.h 
    nodes/FilterNode.h 
    nodes/ImageReaderNode.h 
    nodes/ImageWriterNode.h 
    nodes/SegmentationNode.h 
    pixmapwrapper.h 
    pixmapreaderclass.h 
    Image_p.h 
    drawablelabel.h 
    interactivecomposernode.h
    dtkCreatorMainWindow.h
    dtkCreatorMainWindow_p.h
)

set(${PROJECT_NAME}_SOURCES
    dtkCreatorMainWindow.cpp
    davdcomposernodefactory.cpp 
    Image.cpp 
    SegmentationProcess.cpp 
    FilterProcess.cpp 
    nodes/FilterNode.cpp 
    nodes/ImageReaderNode.cpp 
    nodes/ImageWriterNode.cpp 
    nodes/SegmentationNode.cpp 
    pixmapwrapper.cpp 
    pixmapreaderclass.cpp 
    drawablelabel.cpp 
    interactivecomposernode.cpp
    main.cpp
 )
add_executable (davd ${davd_HEADERS} ${davd_SOURCES})


target_link_libraries(${PROJECT_NAME}
  dtkCoreSupport
  #dtkCore
  dtkComposerSupport
  #dtkComposer
  dtkDistributedSupport
  dtkGuiSupport
  dtkLog
  #davdComposer
  )
  
  qt5_use_modules(${PROJECT_NAME} Core)
qt5_use_modules(${PROJECT_NAME} Xml)
qt5_use_modules(${PROJECT_NAME} Widgets)
qt5_use_modules(${PROJECT_NAME} Gui)



## ###################################################################
## Beautifying
## ###################################################################

mark_as_advanced(${PROJECT_NAME}_VERSION_MAJOR)
mark_as_advanced(${PROJECT_NAME}_VERSION_MINOR)
mark_as_advanced(${PROJECT_NAME}_VERSION_BUILD)

mark_as_advanced(Qt5Concurrent_DIR)
mark_as_advanced(Qt5Core_DIR)
mark_as_advanced(Qt5Declarative_DIR)
mark_as_advanced(Qt5Gui_DIR)
mark_as_advanced(Qt5Network_DIR)
mark_as_advanced(Qt5OpenGL_DIR)
mark_as_advanced(Qt5Qml_DIR)
mark_as_advanced(Qt5Quick_DIR)
mark_as_advanced(Qt5QuickTest_DIR)
mark_as_advanced(Qt5Test_DIR)
mark_as_advanced(Qt5Script_DIR)
mark_as_advanced(Qt5Widgets_DIR)
mark_as_advanced(Qt5Xml_DIR)

install(TARGETS ${PROJECT_NAME}
   BUNDLE DESTINATION bin
  RUNTIME DESTINATION bin)
