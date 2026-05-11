#include "segment_tree.h"
#include <iostream>


template<typename seg_info>
int segment_tree<seg_info>::get_left_child(int node) {
    return (2 * node + 1);
}

template<typename seg_info>
int segment_tree<seg_info>::get_right_child(int node) {
    return (2 * node + 2);
}

template<typename seg_info>
void segment_tree<seg_info>::update_node_from_childs(int node) {
    tree[node] = tree[get_left_child(node)] + tree[get_right_child(node)];
}

template<typename seg_info>
void segment_tree<seg_info>::initialize_tree(int array_size) {
    neutral_element = seg_info(0);
    root_tree = 0;

    segment_tree_size = 1;
    while (segment_tree_size < array_size) {
        segment_tree_size *= 2;
    }
    tree.assign(2 * segment_tree_size - 1, neutral_element);
}

template<typename seg_info>
void segment_tree<seg_info>::build_tree(const std::vector<seg_info>& values, int node, int curr_l, int curr_r) {
    if (curr_r - curr_l == 1) {
        if (curr_l < (static_cast<int>(values.size()))) {
            tree[node].sum_on_seg = values[curr_l];
        }
        return;
    }
    int curr_m = (curr_l + curr_r) / 2;
    build_tree(values, get_left_child(node), curr_l, curr_m);
    build_tree(values, get_right_child(node), curr_m, curr_r);
    update_node_from_childs(node);
}

template<typename seg_info>
void segment_tree<seg_info>::point_update(int pos, seg_info new_value, int node, int curr_l, int curr_r) {
    if (curr_r - curr_l == 1) {
        tree[node].sum_on_seg = new_value;
        return;
    }
    int curr_m = (curr_l + curr_r) / 2;
    if (pos < curr_m) {
        point_update(pos, new_value, get_left_child(node), curr_l, curr_m);
    } else {
        point_update(pos, new_value, get_right_child(node), curr_m, curr_r);
    }
    update_node_from_childs(node);
}

template<typename seg_info>
seg_info segment_tree<seg_info>::range_sum(int query_l, int query_r, int node, int curr_l, int curr_r) {
    if (query_l <= curr_l && curr_r <= query_r) return tree[node];
    if (curr_r <= query_l || query_r <= curr_l) return neutral_element;
    int curr_m = (curr_l + curr_r) / 2;
    return (range_sum(query_l, query_r, get_left_child(node), curr_l, curr_m) + range_sum(query_l, query_r, get_right_child(node), curr_m, curr_r));
}

template<typename seg_info>
void segment_tree<seg_info>::point_update(int pos, seg_info new_value) {
    point_update(pos, new_value, root_tree, 0, segment_tree_size);
}

template<typename seg_info>
seg_info segment_tree<seg_info>::range_sum(int query_l, int query_r) {
    query_r += 1; // converting to half-interval
    return segment_tree::range_sum(query_l, query_r, root_tree, 0, segment_tree_size).sum_on_seg;
}

template<typename seg_info>
segment_tree<seg_info>::segment_tree(int array_size) {
    initialize_tree(array_size);
}

template<typename seg_info>
segment_tree<seg_info>::segment_tree(const std::vector<seg_info>& values) {
    initialize_tree(static_cast<int>(values.size()));
    build_tree(values, root_tree, 0, segment_tree_size);
}
