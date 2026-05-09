#include "segment_tree.h"
#include <iostream>

using namespace std;
using ll = long long;


seg_info operator+(const seg_info& left, const seg_info& right) {
    seg_info result;
    result.sum_on_seg = (left.sum_on_seg + right.sum_on_seg);
    return result;
}

int segment_tree::get_left_child(int node) {
    return (2 * node + 1);
}

int segment_tree::get_right_child(int node) {
    return (2 * node + 2);
}

void segment_tree::update_node_from_childs(int node) {
    tree[node] = tree[get_left_child(node)] + tree[get_right_child(node)];
}

void segment_tree::initialize_tree(int array_size) {
    neutral_element = seg_info(0);
    root_tree = 0;

    segment_tree_size = 1;
    while (segment_tree_size < array_size) {
        segment_tree_size *= 2;
    }
    tree.assign(2 * segment_tree_size - 1, neutral_element);
}

void segment_tree::build_tree(const vector<int>& values, int node, int curr_l, int curr_r) {
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

void segment_tree::point_update(int pos, int new_value, int node, int curr_l, int curr_r) {
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

seg_info segment_tree::range_sum(int query_l, int query_r, int node, int curr_l, int curr_r) {
    if (query_l <= curr_l && curr_r <= query_r) return tree[node];
    if (curr_r <= query_l || query_r <= curr_l) return neutral_element;
    int curr_m = (curr_l + curr_r) / 2;
    return (range_sum(query_l, query_r, get_left_child(node), curr_l, curr_m) + range_sum(query_l, query_r, get_right_child(node), curr_m, curr_r));
}

void segment_tree::point_update(int pos, int new_value) {
    point_update(pos, new_value, root_tree, 0, segment_tree_size);
}

ll segment_tree::range_sum(int query_l, int query_r) {
    query_r += 1; // converting to half-interval
    return segment_tree::range_sum(query_l, query_r, root_tree, 0, segment_tree_size).sum_on_seg;
}

segment_tree::segment_tree(int array_size) {
    initialize_tree(array_size);
}

segment_tree::segment_tree(const vector<int>& values) {
    initialize_tree(static_cast<int>(values.size()));
    build_tree(values, root_tree, 0, segment_tree_size);
}
