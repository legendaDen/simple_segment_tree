#include "test_generator_simple.h"


const int MAX_ARRAY_SIZE = 50;
const int MAX_QUERIES_NUM = 100;
const int MIN_VALUE = -100;
const int MAX_VALUE = 100;


void run_case() {
    int n = gen_random_value_seg(1, MAX_ARRAY_SIZE);
    std::vector <int> values = generate_array(n, MIN_VALUE, MAX_VALUE);
    int q = gen_random_value_seg(1, MAX_QUERIES_NUM);
    std::cout << n << std::endl;
    for (auto value : values) std::cout << value << ' ';
    std::cout << std::endl;
    std::cout << q << std::endl;
    for (int i = 0; i < q; ++i) {
        int type = gen_random_value_seg(1, 2);
        std::cout << type << ' ';
        if (type == 1) {
            int pos = gen_random_value_seg(1, n);
            int new_value = gen_random_value_seg(MIN_VALUE, MAX_VALUE);
            std::cout << pos << ' ' << new_value << std::endl;
        } else if (type == 2) {
            int l = gen_random_value_seg(1, n);
            int r = gen_random_value_seg(l, n);
            std::cout << l << ' ' << r << std::endl;
        } else {
            assert(false);
        }
    }
}

int main() {
    int test = 1;
    std::cout << test << std::endl;
    std::cout << std::endl;
    while (test--) run_case();

    return 0;
}