add_library(segment_tree_lib STATIC segment_tree.cpp)

target_include_directories(segment_tree_lib PUBLIC .)

set_target_properties(segment_tree_lib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)