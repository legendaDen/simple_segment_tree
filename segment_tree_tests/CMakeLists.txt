add_executable(segment_tree_test segment_tree_test.cpp)

target_link_libraries(segment_tree_test segment_tree_lib)

set_target_properties(segment_tree_test PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)