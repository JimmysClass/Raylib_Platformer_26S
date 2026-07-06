cmake_minimum_required( VERSION 3.30 )

# Global Settings
set_property( GLOBAL PROPERTY USE_FOLDERS ON )

# Solution
project( GameSolution VERSION 0.0.1 )

set( CMAKE_CONFIGURATION_TYPES Debug Release )

# Visual Studio Settings
if( MSVC )
    set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /ZI" ) # Program Database for Edit and Continue
endif()

###################
# Libraries
###################

add_subdirectory( Libraries )

###################
# Game Project
###################

# File Setup
file( GLOB_RECURSE GameSourceFiles
    Source/*.cpp
    Source/*.h
    .gitignore
    GenerateProjectFiles.bat
    BuildEmscripten.bat
)
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${GameSourceFiles} )

# Project Creation
if( MSVC )
    set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup" )
endif()

add_executable( GameProject ${GameSourceFiles} )

target_include_directories( GameProject PUBLIC
    Libraries/raylib/src
    Source
)

# Preprocessor Definitions
target_compile_definitions( GameProject PUBLIC GAME_PROJECT )

# Libraries to Link
target_link_libraries( GameProject PUBLIC
    raylib
)

# Visual Studio Settings
if( MSVC )
    # Startup Project
    set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GameProject )

    # Debug working directory
    set_property( TARGET GameProject PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}" )
endif()

# WebAssembly Settings
if( EMSCRIPTEN )
	set_target_properties( GameProject PROPERTIES SUFFIX ".html" )
	target_link_options( GameProject PRIVATE
        --preload-file=Data -sUSE_GLFW=3 -sASSERTIONS=1
        -sWASM=1 -sASYNCIFY -sGL_ENABLE_GET_PROC_ADDRESS=1
    )
endif()
