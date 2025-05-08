/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 03-05-2025 22:22:13
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
const long long INF = INT_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
#define int long long
int I = 0, Test = 1;

/**
 * 1, 4, 9, 16
 * x . . . . . . . . x . . . . . . . . x
 * x . . x
 * 1000000 1 1 2 2 3 3 4 4 1000000 5 5 6 6 7 7 8 8 9 10 9 11 12 10 11 1000000 12 
 *
 */

map<int, int> mp;
void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    if ((n & 1) && n <= 25) {
        cout << -1;
        return;
    }

    vector<int> v(n);
    if (n & 1) {
        v[0] = 1e6;
        v[9] = 1e6;
        v[25] = 1e6;
        v[26] = 1e6 - 1;
        v[10] = 1e6 - 1;
    }

    for (int i = 0; i < n; i++) {
        if (!v[i]) {
            v[i] = k / 2 + 1;
            k++;
        }
    }

    for (auto &i : v) {
        cout << i << " ";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef SUBLIME
    free
#endif
        for (int i = 3; (i * i) * 2 + 1 <= 1e6; i += 2) {
        mp[(i * i) * 2 + 1] = i;
    }
    cin >> Test;
    for (I = 1; I <= Test; I++) {
        dclear(I);
        solve();
        cout << endl;
    }
}
