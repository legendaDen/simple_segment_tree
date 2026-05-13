#!/bin/bash

g++ segment_tree_test.cpp ../segment_tree_lib/segment_tree.cpp -o segment_tree_test


# unit tests

./segment_tree_test < unit_tests/test1_input.txt > segment_tree_test_result.txt

read res1_unit < segment_tree_test_result.txt
read res2_unit < unit_tests/test1_answer.txt

if [ "$res1" != "$res2" ]; then
    echo "Segment tree gives incorrect answers. You can find problem test inside unit_tests/test1_answer.txt"
    exit 1
fi

echo "Unit tests passed!"


# stress tests

g++ generate_test_segment_tree.cpp -o generate_test_segment_tree
g++ naive_segment_tree.cpp -o naive_segment_tree

current_iter=0

while true; do
    ./generate_test_segment_tree > segment_tree_test_stresser.txt
    ./segment_tree_test < segment_tree_test_stresser.txt > segment_tree_test_result.txt
    ./naive_segment_tree < segment_tree_test_stresser.txt > naive_segment_tree_result.txt

    read res1 < segment_tree_test_result.txt
    read res2 < naive_segment_tree_result.txt

    current_iter=$((current_iter + 1))

    if [ "$res1" != "$res2" ]; then
        echo "Segment tree gives incorrect answers. You can find problem test inside segment_tree_test_stresser.txt"
        exit 1
    fi

    if [ "$current_iter" == "$69" ]; then
        echo "Stress tests passed!"
        exit 1
    fi

done
