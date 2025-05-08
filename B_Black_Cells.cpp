/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 04-05-2025 01:41:21
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

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) {
        cin >> i;
    }
    if ((n & 1) == 0) {
        for (int i = 0; i + 1 < n; i += 2) {
            ans = max(ans, v[i + 1] - v[i]);
        }
        cout << ans;
        return;
    }
    ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        // left side
        int diff = 1;
        for (int j = 0; j + 1 <= i; j += 2) {
            diff = max(diff, v[j + 1] - v[j]);
        }
        int init2 = -1;
        if ((i + 1) & 1) {
            init2 = i + 1;
        } else {
            init2 = i + 2;
        }
        for (int j = init2; j + 1 < n; j+=2) {
            diff = max(diff, v[j + 1] - v[j]);
        }
        ans = min(ans, diff);
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
