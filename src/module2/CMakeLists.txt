add_library(module2
    application.cpp
    application_detail.cpp
)

target_include_directories(module2
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(module2
    PRIVATE
        module1
)
