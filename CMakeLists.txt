cmake_minimum_required (VERSION 3.8)
project (Books)

# output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/)
set(INSTALL_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME})
set(DATA_DIRECTORY ${CMAKE_SOURCE_DIR}/data)

# Compiler options (for all targets)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
    add_compile_options(/W3)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else ()
    add_compile_options(-Wall -Wextra -pedantic -Wshadow -Wconversion)

    if(CMAKE_COMPILE_WARNING_AS_ERROR)
        add_compile_options(-Werror)
    endif()
endif ()

# For Clion/VSCode
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# additional include directories
include_directories(inc)

add_subdirectory(src)

# store executables in proper debug/release folders
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/debug
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/release
)

# installation (move release files to bin)
install(
    TARGETS ${PROJECT_NAME}
    DESTINATION ${INSTALL_DIRECTORY}
    CONFIGURATIONS Release
)

# copy data/ folder to installation directory
if(EXISTS ${DATA_DIRECTORY})
    install(DIRECTORY ${DATA_DIRECTORY} DESTINATION ${INSTALL_DIRECTORY})
endif()