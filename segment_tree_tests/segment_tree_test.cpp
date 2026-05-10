#include "../segment_tree_lib/segment_tree.h"
#include <iostream>
#include <vector>


void run_case() {
    int n;
    std::cin >> n;
    std::vector <int> values(n);
    for (auto& value : values) {
        std::cin >> value;
    }
    segment_tree tree(values);
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
            std::cout << tree.range_sum(l, r) << std::endl;
        }
    }
}

int main() {
    int test = 1;
    std::cin >> test;
    while (test--) run_case();

    return 0;
}