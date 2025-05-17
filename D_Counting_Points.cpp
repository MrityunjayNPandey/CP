/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 12-05-2025 17:20:42
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
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
#define int long long
int I = 0, Test = 1;
set<pair<int, int>> s;

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<int> v(n), r(n);
    for (auto &i : v) {
        cin >> i;
    }
    for (auto &i : r) {
        cin >> i;
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = v[i] - r[i]; j <= v[i] + r[i]; j++) {
            int p = sqrt(r[i] * r[i] - (j - v[i]) * (j - v[i]));
            mp[j] = max(mp[j], p);
        }
    }
    debug(mp);
    for (auto &[l, r] : mp) {
        ans += 2 * r + 1;
    }
    cout << ans;
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
        cout << endl;
    }
}
