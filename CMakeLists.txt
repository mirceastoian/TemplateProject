cmake_minimum_required(VERSION 3.21)

project(ModuleOrganizationDemo VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

function(add_modules_under directory)
    file(GLOB children CONFIGURE_DEPENDS LIST_DIRECTORIES true "${directory}/*")

    foreach(child IN LISTS children)
        if(IS_DIRECTORY "${child}")
            if(EXISTS "${child}/CMakeLists.txt")
                get_filename_component(module_name "${child}" NAME)
                add_subdirectory("${child}" "${CMAKE_CURRENT_BINARY_DIR}/modules/${module_name}")
            else()
                add_modules_under("${child}")
            endif()
        endif()
    endforeach()
endfunction()

add_modules_under("${PROJECT_SOURCE_DIR}/src")

add_executable(module_demo src/main.cpp)
target_link_libraries(module_demo PRIVATE module2)
