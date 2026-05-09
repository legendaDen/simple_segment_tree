#include <iostream>
#include <vector>


using namespace std;
using ll = long long;


ll range_sum_naive(const vector<int>& values, int l, int r) {
    ll sum = 0;
    for (int i = l; i <= r; ++i) sum += values[i];
    return sum;
}

void run_case() {
    int n;
    cin >> n;
    vector <int> values(n);
    for (auto& value : values) {
        cin >> value;
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int pos, new_value;
            cin >> pos >> new_value;
            --pos;
            values[pos] = new_value;
        } else if (t == 2) {
            int l, r; cin >> l >> r;
            --l; --r;
            cout << range_sum_naive(values, l, r) << endl;
        }
    }
}

int main() {
    int test = 1;
    cin >> test;
    while (test--) run_case();

    return 0;
}