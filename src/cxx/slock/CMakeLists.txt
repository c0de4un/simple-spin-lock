# // ------------------------------------------------------------------------------
#
# This is CMake-Project for simple-spinner-lock library.
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
set ( PROJECT_NAME "slock" )

# Project Version
set ( PROJECT_VERSION 1.0.0 )

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

option ( SLOCK_BUILD_STATIC "Build STATIC Library ?" ON )
option ( SLOCK_BUILD_SHARED "Build SHARED (dynamic) Library ?" OFF )

# Binary Output Dir
option ( BIN_DIR "Output Binaries directory." "${CMAKE_SOURCE_DIR}/bin/${PLATFORM_DIR}/${BUILD_TYPE_DIR}" )

# =================================================================================
# HEADERS
# =================================================================================

set ( SLOCK_HEADERS
	"public/Mutex.hpp"
	"public/SpinLock.hpp"
    "public/slock.hpp" )

# =================================================================================
# SOURCES
# =================================================================================

set ( SLOCK_SOURCES
	"private/Mutex.cpp"
	"private/SpinLock.cpp"
    "private/slock.cpp")

# =================================================================================
# BUILD
# =================================================================================

# Build Library
if ( SLOCK_BUILD_STATIC ) # STATIC Library
	add_library ( slock STATIC ${SLOCK_SOURCES} ${SLOCK_HEADERS} )
elseif ( SLOCK_BUILD_SHARED )
	# Export all Symbols by default (on Windows creates '.lib'+ '.dll').
	set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
	
	# Create SHARED Library Object
	add_library ( slock SHARED ${SLOCK_SOURCES} )

	# Configure SHARED Library Object
	set_target_properties ( slock PROPERTIES
		PUBLIC_HEADER ${SLOCK_HEADERS}
		RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
		VERSION ${PROJECT_VERSION} )
endif ( SLOCK_BUILD_STATIC )

# =================================================================================
# INSTALL
# =================================================================================

# Install STATIC Library
if ( SLOCK_BUILD_STATIC )
	install ( TARGETS slock LIBRARY DESTINATION "lib" ARCHIVE DESTINATION "lib/static" )
endif ( SLOCK_BUILD_STATIC )

# Install SHARED Library
if ( SLOCK_BUILD_SHARED )
	install ( TARGETS slock LIBRARY DESTINATION "lib/shared" )
endif ( SLOCK_BUILD_SHARED )