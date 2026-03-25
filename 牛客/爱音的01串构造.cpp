/*
https://ac.nowcoder.com/acm/contest/120564/F
思路解析： 
*/
#include <iostream>
#include <string>

using namespace std;

/**
 * 思路：
 * 总 MEX = (包含0的子串数) + (同时包含0和1的子串数)
 * 设 T 为总子串数，f(0s) 为全0子串数，f(1s) 为全1子串数
 * 总 MEX = (T - f(1s)) + (T - f(0s) - f(1s)) = 2T - f(0s) - 2f(1s)
 * 目标：最小化 f(0s) + 2f(1s)。
 * 通过将数量较多的字符尽可能均匀地由数量较少的字符隔开来达到目的。
 */

void solve() {
    int a, b;
    if (!(cin >> a >> b)) return;

    if (a > b) {
        // 0 多，用 1 来隔开 0
        int k = b + 1; // 份数
        int q = a / k; // 每份基础个数
        int r = a % k; // 余数分配
        for (int i = 0; i < k; ++i) {
            int current_zeros = q + (i < r ? 1 : 0);
            for (int j = 0; j < current_zeros; ++j) cout << '0';
            if (i < b) cout << '1'; // 最后一个 0 块后不加 1
        }
        cout << '\n';
    } else {
        // 1 多或相等，用 0 来隔开 1
        int k = a + 1;
        int q = b / k;
        int r = b % k;
        for (int i = 0; i < k; ++i) {
            int current_ones = q + (i < r ? 1 : 0);
            for (int j = 0; j < current_ones; ++j) cout << '1';
            if (i < a) cout << '0'; // 最后一个 1 块后不加 0
        }
        cout << '\n';
    }
}

int main() {
    // 优化 I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

