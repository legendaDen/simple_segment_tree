#include <iostream>
#include <vector>
#include <cassert>


int range_sum_naive(const std::vector<int>& values, int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; ++i) sum += values[i];
    return sum;
}

void run_case() {
    int n;
    std::cin >> n;
    std::vector <int> values(n);
    for (auto& value : values) {
        std::cin >> value;
    }
    int q;
    std::cin >> q;
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int pos, new_value;
            std::cin >> pos >> new_value;
            --pos;
            values[pos] = new_value;
        } else if (type == 2) {
            int l, r; std::cin >> l >> r;
            --l; --r;
            std::cout << range_sum_naive(values, l, r) << std::endl;
        } else {
            assert(false);
        }
    }
}

int main() {
    int test = 1;
    std::cin >> test;
    while (test--) run_case();

    return 0;
}