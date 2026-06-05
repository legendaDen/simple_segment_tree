#include<iostream>
#include<vector>
#include<concepts>


template<typename seg_info>
class segment_tree {
private:
    size_t segment_tree_size;
    size_t root_tree;
    seg_info neutral_element;
    std::vector<seg_info> tree;

    size_t get_left_child(size_t);

    size_t get_right_child(size_t);

    void update_node_from_childs(size_t);

    void initialize_tree(size_t);

    void build_tree(const std::vector<seg_info>&, size_t, size_t, size_t);

    void point_update(size_t, seg_info, size_t, size_t, size_t);

    seg_info range_query(size_t, size_t, size_t, size_t, size_t);

public:
    void point_update(size_t, seg_info);

    seg_info range_query(size_t, size_t);

    segment_tree(size_t);

    segment_tree(const std::vector<seg_info>&);

};


template<typename seg_info>
size_t segment_tree<seg_info>::get_left_child(size_t node) {
    return (2 * node + 1);
}

template<typename seg_info>
size_t segment_tree<seg_info>::get_right_child(size_t node) {
    return (2 * node + 2);
}

template<typename seg_info>
void segment_tree<seg_info>::update_node_from_childs(size_t node) {
    tree[node] = tree[get_left_child(node)] + tree[get_right_child(node)];
}

template<typename seg_info>
void segment_tree<seg_info>::initialize_tree(size_t array_size) {
    neutral_element = seg_info(0);
    root_tree = 0;

    segment_tree_size = 1;
    while (segment_tree_size < array_size) {
        segment_tree_size *= 2;
    }
    tree.assign(2 * segment_tree_size - 1, neutral_element);
}

template<typename seg_info>
void segment_tree<seg_info>::build_tree(const std::vector<seg_info>& values, size_t node, size_t curr_l, size_t curr_r) {
    if (curr_r - curr_l == 1) {
        if (curr_l < values.size()) {
            tree[node] = values[curr_l];
        }
        return;
    }
    size_t curr_m = (curr_l + curr_r) / 2;
    build_tree(values, get_left_child(node), curr_l, curr_m);
    build_tree(values, get_right_child(node), curr_m, curr_r);
    update_node_from_childs(node);
}

template<typename seg_info>
void segment_tree<seg_info>::point_update(size_t pos, seg_info new_value, size_t node, size_t curr_l, size_t curr_r) {
    if (curr_r - curr_l == 1) {
        tree[node] = new_value;
        return;
    }
    size_t curr_m = (curr_l + curr_r) / 2;
    if (pos < curr_m) {
        point_update(pos, new_value, get_left_child(node), curr_l, curr_m);
    } else {
        point_update(pos, new_value, get_right_child(node), curr_m, curr_r);
    }
    update_node_from_childs(node);
}

template<typename seg_info>
seg_info segment_tree<seg_info>::range_query(size_t query_l, size_t query_r, size_t node, size_t curr_l, size_t curr_r) {
    if (query_l <= curr_l && curr_r <= query_r) return tree[node];
    if (curr_r <= query_l || query_r <= curr_l) return neutral_element;
    size_t curr_m = (curr_l + curr_r) / 2;
    return (range_query(query_l, query_r, get_left_child(node), curr_l, curr_m) + range_query(query_l, query_r, get_right_child(node), curr_m, curr_r));
}

template<typename seg_info>
void segment_tree<seg_info>::point_update(size_t pos, seg_info new_value) {
    point_update(pos, new_value, root_tree, 0, segment_tree_size);
}

template<typename seg_info>
seg_info segment_tree<seg_info>::range_query(size_t query_l, size_t query_r) {
    return segment_tree::range_query(query_l, query_r, root_tree, 0, segment_tree_size);
}

template<typename seg_info>
segment_tree<seg_info>::segment_tree(size_t array_size) {
    initialize_tree(array_size);
}

template<typename seg_info>
segment_tree<seg_info>::segment_tree(const std::vector<seg_info>& values) {
    initialize_tree(values.size());
    build_tree(values, root_tree, 0, segment_tree_size);
}
