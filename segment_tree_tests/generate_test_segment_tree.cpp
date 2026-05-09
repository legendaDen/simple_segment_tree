#include "test_generator_simple.h"


const int MAX_ARRAY_SIZE = 30;
const int MAX_QUERIES_NUM = 30;
const int MIN_VALUE = -100;
const int MAX_VALUE = 100;


void run_case() {
    int n = gen_random_value_seg(1, MAX_ARRAY_SIZE);
    vector <int> values = generate_array(n, MIN_VALUE, MAX_VALUE);
    int q = gen_random_value_seg(1, MAX_QUERIES_NUM);
    cout << n << endl;
    for (auto value : values) cout << value << ' ';
    cout << endl;
    cout << q << endl;
    for (int i = 0; i < q; ++i) {
        int t = gen_random_value_seg(1, 2);
        cout << t << ' ';
        if (t == 1) {
            int pos = gen_random_value_seg(1, n);
            int new_value = gen_random_value_seg(MIN_VALUE, MAX_VALUE);
            cout << pos << ' ' << new_value << endl;
        } else if (t == 2) {
            int l = gen_random_value_seg(1, n);
            int r = gen_random_value_seg(l, n);
            cout << l << ' ' << r << endl;
        } else {
            assert(false);
        }
    }
}

int main() {
    int test = 1;
    cout << test << endl;
    cout << endl;
    while (test--) run_case();

    return 0;
}