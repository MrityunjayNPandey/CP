/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 27-04-2025 03:27:56
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

int calculate(auto &disp, auto &ind, auto &modified) {
    debug(ind);
    modified[ind - 1] = 1;
    if (disp[ind - 1] == ind) {
        return 1;
    }
    int altInd = disp[ind - 1];
    disp[ind - 1] = ind;
    return (disp[altInd - 1] != altInd ? calculate(disp, altInd, modified) : 0) + 1;
}

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    // get the original positions
    // use the ans for next result
    cin >> n;
    vector<int> v(n), q(n), displaced(n), modified(n);
    for (auto &i : v) {
        cin >> i;
    }
    for (auto &i : q) {
        cin >> i;
    }
    for (int i = 0; i < n; i++) {
        displaced[v[i] - 1] = i + 1;
    }
    debug(displaced);
    for (auto &i : q) {
        debug(i);
        if (!modified[i - 1]) {
            ans += calculate(displaced, i, modified);
        }
        cout << ans << " ";
    }
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
