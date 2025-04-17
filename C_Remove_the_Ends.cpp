/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 26-02-2025 06:02:21
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
#define free                                                                   \
    freopen("input.txt", "r", stdin);                                          \
    freopen("output.txt", "w", stdout);                                        \
    freopen("error.txt", "w", stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_map;
#define int long long

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) {
        cin >> i;
    }
    vector<int> pref(n), suff(n);
    if (v[0] > 0)
        pref[0] = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > 0) {
            pref[i] += v[i];
        }
        pref[i] += pref[i - 1];
    }
    if (v[n - 1] < 0)
        suff[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] < 0) {
            suff[i] += v[i];
        }
        suff[i] += suff[i + 1];
    }
    debug(pref, suff);
    for (int i = 0; i < n; i++) {
        ans = max(ans, pref[i] - suff[i]);
    }
    cout << ans;
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
