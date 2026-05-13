#ifndef segment_tree_h
#define segment_tree_h

#include <iostream>
#include <vector>


template<typename seg_info>
class segment_tree {
private:
    int segment_tree_size;
    int root_tree;
    seg_info neutral_element;
    std::vector <seg_info> tree;

    int get_left_child(int);

    int get_right_child(int);

    void update_node_from_childs(int);

    void initialize_tree(int);

    void build_tree(const std::vector<seg_info>&, int, int, int);

    void point_update(int, seg_info, int, int, int);

    seg_info range_sum(int, int, int, int, int);

public:
    void point_update(int, seg_info);

    seg_info range_sum(int, int);

    segment_tree(int);

    segment_tree(const std::vector<seg_info>&);


};

#endif
