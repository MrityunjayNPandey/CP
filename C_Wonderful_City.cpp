/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 19-04-2025 21:09:52
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

// row and col operations are independent

bool conflict(auto &v1, auto &v2) {
    int n = v1.size();
    for (int i = 0; i < n; i++) {
        if (v1[i] == v2[i]) {
            // debug(v1, v2);
            return true;
        }
    }
    return false;
}

int getMinOperations(auto &vv, auto &cost, int n) {
    vector<vector<int>> altVV(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            altVV[i][j] += vv[i][j] + 1;
        }
    }

    vector<vector<int>> dp(n, vector<int>(2, INF));
    dp[0][0] = 0;
    dp[0][1] = cost[0];
    for (int i = 1; i < n; i++) {
        if (!conflict(vv[i], vv[i - 1])) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        }
        if (!conflict(vv[i], altVV[i - 1])) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if (!conflict(altVV[i], vv[i - 1])) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0]);
        }
        if (!conflict(altVV[i], altVV[i - 1])) {
            dp[i][1] = min(dp[i][1], dp[i - 1][1]);
        }

        if (dp[i][1] != INF) {
            dp[i][1] += cost[i];
        }
    }

    debug(dp, min(dp[n - 1][0], dp[n - 1][1]));

    return min(dp[n - 1][0], dp[n - 1][1]);
}

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<vector<int>> vv(n, vector<int>(n));
    for (auto &i : vv) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    vector<int> costR(n), costC(n);
    for (auto &i : costR) {
        cin >> i;
    }
    for (auto &i : costC) {
        cin >> i;
    }

    vector<vector<int>> vvT(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vvT[j][i] = vv[i][j];
        }
    }

    int opX = getMinOperations(vv, costR, n);
    int opY = getMinOperations(vvT, costC, n);

    debug(opX, opY);

    if (opX == INF || opY == INF) {
        cout << -1;
        return;
    }
    cout << opX + opY;
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
