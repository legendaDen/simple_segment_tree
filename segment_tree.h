#ifndef segment_tree_h
#define segment_tree_h

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


class seg_info {
public:

    ll sum_on_seg;

    seg_info() : sum_on_seg(0) {}

    seg_info(int value) : sum_on_seg(value) {}


};


class segment_tree : private seg_info {
private:
    int segment_tree_size;
    int root_tree;
    seg_info neutral_element;
    vector <seg_info> tree;

    int get_left_child(int);

    int get_right_child(int);

    void update_node_from_childs(int);

    void initialize_tree(int);

    void build_tree(const vector<int>&, int, int, int);

    void point_update(int, int, int, int, int);

    seg_info range_sum(int, int, int, int, int);

protected:

public:
    void point_update(int, int);

    ll range_sum(int, int);

    segment_tree(int);

    segment_tree(const vector<int>&);


};

#endif