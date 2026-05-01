#include "segment_tree.h"
#include <iostream>
#include <vector>

using namespace std;


void run_case() {
    int n;
    cin >> n;
    vector <int> values(n);
    for (auto& value : values) {
        cin >> value;
    }
    segment_tree tree(values);
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, new_value;
            cin >> pos >> new_value;
            --pos;
            tree.point_update(pos, new_value);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            cout << tree.range_sum(l, r) << endl;
        }
    }
}

int main() {
    int test = 1;
    cin >> test;
    while (test--) run_case();

    return 0;
}