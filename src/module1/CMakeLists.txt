add_library(module1
    module1.cpp
    module1_detail.cpp
)

target_include_directories(module1
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)
