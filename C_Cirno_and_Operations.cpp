/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 24-02-2025 09:50:35
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
#define pb push_back
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
    vector<int> vtemp;
    vtemp = v;
    sum = accumulate(all(v), 0);
    while (vtemp.size() > 1) {
        vector<int> vNew;
        int sumNew = 0;
        for (int i = 1; i < vtemp.size(); i++) {
            int diff = vtemp[i] - vtemp[i - 1];
            vNew.push_back(diff);
            sumNew += diff;
        }
        debug(sumNew);
        sum = max(sum, abs(sumNew));
        vtemp = vNew;
    }
    cout << sum;
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
