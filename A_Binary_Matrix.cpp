/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 18-04-2025 13:58:32
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
#define int long long

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<string> vv(n);
    for (auto &i : vv) {
        cin >> i;
    }
    for (int i = 0; i < n; i++) {
        cnt = 0;
        for (int j = 0; j < m; j++) {
            if (vv[i][j] == '1') {
                cnt++;
            }
        }
        if (cnt & 1) {
            k++;
        }
    }
    int p = 0;
    for (int i = 0; i < m; i++) {
        cnt = 0;
        for (int j = 0; j < n; j++) {
            if (vv[j][i] == '1') {
                cnt++;
            }
        }
        if (cnt & 1) {
            p++;
        }
    }
    cout << max(k, p);
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
