# // ------------------------------------------------------------------------------
#
# This is CMake-Project for simple-spinner-lock library demo.
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
set ( PROJECT_NAME "slock-demo" )

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

# =================================================================================
# HEADERS
# =================================================================================

set ( DEMO_HEADERS
    "main.hpp" )

# =================================================================================
# SOURCES
# =================================================================================

set ( DEMO_SOURCES
    "main.cpp")

# =================================================================================
# RESOURCES
# =================================================================================

# WINDOWS
if ( WIN32 OR WIN64 )
	set ( DEMO_RESOURCES "${CMAKE_SOURCE_DIR}/res/win_res.rc" )
else ( WIN32 OR WIN64 )
	set ( DEMO_RESOURCES "" )
endif ( WIN32 OR WIN64 )

# =================================================================================
# BUILD
# =================================================================================

# Add Executable Object
add_executable ( slock_demo ${DEMO_SOURCES} ${DEMO_HEADERS} ${DEMO_RESOURCES} )

# Configure Executable Object
set_target_properties ( slock_demo PROPERTIES
	CXX_EXTENSIONS FALSE
	OUTPUT_NAME "${PROJECT_NAME}_v${PROJECT_VERSION}"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}" )

# Remove Console Window for Release
#if ( CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo" )
	#set_target_properties( slock_demo PROPERTIES 
	#LINK_FLAGS "/ENTRY:mainCRTStartup /SUBSYSTEM:WINDOWS" )
#endif ( CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo" )

# Link
target_link_libraries ( slock_demo ${slock} )

# Include Headers
target_include_directories ( slock_demo PUBLIC "../slock/public" )

# =================================================================================
# INSTALL
# =================================================================================

install ( TARGETS slock_demo DESTINATION "bin" )