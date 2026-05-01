#include <iostream>
#include <random>
#include <cassert>

using namespace std;


random_device rd;
mt19937 simple_generator(rd());


int gen_random_value_seg(int l, int r) {
    return (l + ((simple_generator()) % (r - l + 1)));
}

vector<int> generate_array(int len, int min_value, int max_value) {
    vector <int> result(len);
    for (int i = 0; i < len; ++i) {
        result[i] = gen_random_value_seg(min_value, max_value);
    }
    return result;
}