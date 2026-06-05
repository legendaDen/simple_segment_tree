#include "../segment_tree_lib/segment_tree.h"
#include <iostream>
#include <vector>



struct SegSum {
public:

    int sum_on_seg;

    SegSum() : sum_on_seg(0) {}

    SegSum(int sum_) : sum_on_seg(sum_) {}


};

SegSum Combine(SegSum a, SegSum b) {
    return SegSum(a.sum_on_seg + b.sum_on_seg);
}

void run_case() {
    int n;
    std::cin >> n;
    std::vector <SegSum> values(n);
    for (auto& value : values) {
        std::cin >> value.sum_on_seg;
    }
    segment_tree<SegSum> tree(values);
    int q;
    std::cin >> q;
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int pos, new_value;
            std::cin >> pos >> new_value;
            --pos;
            tree.point_update(pos, new_value);
        } else if (type == 2) {
            int l, r;
            std::cin >> l >> r;
            --l; --r;
            std::cout << tree.range_query(l, r).sum_on_seg << std::endl;
        }
    }
}

int main() {
    int test = 1;
    std::cin >> test;
    while (test--) run_case();

    return 0;
}