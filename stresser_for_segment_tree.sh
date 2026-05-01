#!/bin/bash

g++ generate_test_segment_tree.cpp -o generate_test_segment_tree
g++ segment_tree_test.cpp -o segment_tree_test
g++ naive_segment_tree.cpp -o naive_segment_tree

current_iter=0

while true; do
    ./generate_test_segment_tree > segment_tree_test_stresser.txt
    ./segment_tree_test < segment_tree_test_stresser.txt > segment_tree_test_result.txt
    ./naive_segment_tree < segment_tree_test_stresser.txt > naive_segment_tree_result.txt

    read res1 < segment_tree_test_result.txt
    read res2 < naive_segment_tree_result.txt

    current_iter++

    if [ "$res1" != "$res2" ]; then
        echo "File segment_tree.cpp has some problems. You can find problem test inside segment_tree_test_stresser.txt"
        exit 1
    fi

    if [ "$current_iter" == "$60" ]; then
        echo "File segment_tree.cpp is fully correct."
        exit 1
    fi

done