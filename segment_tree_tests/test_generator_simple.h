#include <iostream>
#include <random>
#include <cassert>


std::random_device rd;
std::mt19937 simple_generator(rd());


template <typename T>
T gen_random_value_seg(T l, T r) {
    return (l + ((simple_generator()) % (r - l + 1)));
}

template <typename T>
std::vector<T> generate_array(size_t len, T min_value, T max_value) {
    std::vector <T> result(len);
    for (size_t i = 0; i < len; ++i) {
        result[i] = gen_random_value_seg(min_value, max_value);
    }
    return result;
}