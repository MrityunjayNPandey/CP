/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 21-04-2025 16:58:49
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
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
#define int long long
int I = 0, Test = 1;

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<pair<vector<int>, int>> vv(n, {vector<int>(m, 0), -1});
    for (auto &[i, ind] : vv) {
        for (auto &j : i) {
            cin >> j;
        }
        ind = ++k;
        sort(i.begin(), i.end());
    }
    sort(vv.begin(), vv.end());
    debug(vv);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (vv[i].first[j + 1] - vv[i].first[j] != n) {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (auto &[_i, ind] : vv) {
        cout << ind << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef SUBLIME
    free
#endif
            cin >>
        Test;
    for (I = 1; I <= Test; I++) {
        dclear(I);
        solve();
    }
}
