# // ------------------------------------------------------------------------------
#
# This is CMake-Project for simple-spinner-lock example-project.
#
# License: see "LICENSE" file.
#
# // ------------------------------------------------------------------------------

# =================================================================================
# CMake Meta-Data
# =================================================================================

# CMake-Version
cmake_minimum_required ( VERSION 3.5 FATAL_ERROR ) # QT5 + CMake required 3.5 minimum.

# =================================================================================
# PROJECT
# =================================================================================

# Project Name
set ( PROJECT_NAME "simple-spin-lock" )

# Project Version
set ( PROJECT_VERSION 0.0.1 )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C CXX )

# C++ Version
set ( CMAKE_CXX_STANDARD 11 )
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# =================================================================================
# CONFIGS
# =================================================================================

# Prefix to headers & sources dir.
set ( PROJECT_SRC_DIR_PREFIX "src/cxx/" )

# DEBUG
if ( CMAKE_BUILD_TYPE STREQUAL "Debug" )
	add_definitions ( -DDEBUG=1 )
endif ( CMAKE_BUILD_TYPE STREQUAL "Debug" )

# =================================================================================
# MODULES
# =================================================================================

# Library
add_subdirectory ( "${PROJECT_SRC_DIR_PREFIX}slock" )

# Executable
add_subdirectory ( "${PROJECT_SRC_DIR_PREFIX}demo" )