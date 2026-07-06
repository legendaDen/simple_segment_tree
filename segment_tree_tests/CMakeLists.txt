add_executable(segment_tree_tests
    unit_test.cpp
    stress_test.cpp
)

target_link_libraries(segment_tree_tests
    PRIVATE
    segment_tree_lib
    GTest::gtest_main
)

set_target_properties(segment_tree_tests PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

include(GoogleTest)
gtest_discover_tests(segment_tree_tests)