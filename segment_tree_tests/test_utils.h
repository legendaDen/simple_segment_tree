#include <vector>

struct SegSum {
    int sum_on_seg = 0;

    SegSum() = default;
    explicit SegSum(int sum_) : sum_on_seg(sum_) {}
};

SegSum Combine(SegSum a, SegSum b) {
    return SegSum(a.sum_on_seg + b.sum_on_seg);
}

std::vector<SegSum> ToSegSum(const std::vector<int>& values) {
    std::vector<SegSum> result;
    result.reserve(values.size());
    for (int value : values) {
        result.emplace_back(value);
    }
    return result;
}

int NaiveRangeSum(const std::vector<int>& values, size_t l, size_t r) {
    int sum = 0;
    for (size_t i = l; i < r; ++i) sum += values[i];
    return sum;
}