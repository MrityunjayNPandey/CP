/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 20-04-2025 18:09:49
 **/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...)
#define print(x)
#define dclear(x)
#endif
#define free                            \
    freopen("input.txt", "r", stdin);   \
    freopen("output.txt", "w", stdout); \
    freopen("error.txt", "w", stderr);
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
#define int long long
void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    string str1, str2;
    cin >> n;
    cin >> str1;
    cin >> str2;
    int num1Odd = 0, num1Even = 0, num0Odd = 0, num0Even = 0;
    for (int i = 0; i < n; i++) {
        if (str1[i] == '1') {
            if (i & 1) {
                num1Odd++;
            } else {
                num1Even++;
            }
        }
        if (str2[i] == '0') {
            if (i & 1) {
                num0Odd++;
            } else {
                num0Even++;
            }
        }
    }
    if (num0Even < num1Odd || num0Odd < num1Even) {
        cout << "NO";
        return;
    }
    cout << "YES";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    cin >> Test;
    for (int I = 1; I <= Test; I++) {
        dclear(I);
        solve();
        cout << endl;
    }
}
