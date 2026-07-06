cmake_minimum_required( VERSION 3.30 )

###################
# GLFW Library
###################

# File Setup
file( GLOB_RECURSE GLFWSourceFiles
    raylib/src/external/glfw/src/*.c
    raylib/src/external/glfw/src/*.h
    raylib/src/external/glfw/src/*.m
)
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR}/raylib/src/external/glfw FILES ${GLFWSourceFiles} )

# Project Creation
add_library( glfw ${GLFWSourceFiles} )

# Include Directories
target_include_directories( glfw PUBLIC
    raylib/src/external/glfw/include
)

# Defines
if( MSVC )
    target_compile_definitions( glfw PUBLIC _GLFW_WIN32 )
endif()

if( APPLE )
    target_compile_definitions( glfw PUBLIC _GLFW_COCOA )
endif()

###################
# Raylib Library
###################

# File Setup
file( GLOB_RECURSE RaylibSourceFiles
    raylib/src/raudio.c
    raylib/src/rcore.c
    raylib/src/rmodels.c
    raylib/src/rshapes.c
    raylib/src/rtext.c
    raylib/src/rtextures.c
    raylib/src/utils.c
    raylib/src/*.h
)
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR}/raylib FILES ${RaylibSourceFiles} )

# Project Creation
add_library( raylib ${RaylibSourceFiles} )

# Libraries to Link
if( MSVC )
    target_link_libraries( raylib
        glfw
        winmm
    )
endif()

if( APPLE )
    target_link_libraries( raylib
        glfw
        "-framework IOKit"
        "-framework Cocoa"
        "-framework OpenGL"
        "-framework CoreVideo"
    )
endif()

if( MSVC )
    target_compile_definitions( raylib PUBLIC PLATFORM_DESKTOP )
    target_compile_definitions( raylib PUBLIC GRAPHICS_API_OPENGL_33 )
    target_compile_options( raylib PRIVATE /experimental:external /external:W0 )
endif()

if( EMSCRIPTEN )
    target_compile_definitions( raylib PUBLIC PLATFORM_WEB )
    target_compile_definitions( raylib PUBLIC GRAPHICS_API_OPENGL_ES2 )
endif()

if( APPLE )
    target_compile_definitions( raylib PUBLIC PLATFORM_DESKTOP )
    target_compile_definitions( raylib PUBLIC GRAPHICS_API_OPENGL_33 )
endif()
