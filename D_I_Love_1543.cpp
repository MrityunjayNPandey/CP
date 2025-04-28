/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 28-04-2025 16:08:44
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
    cin >> n >> m;
    vector<string> vStr(n);
    for (auto &i : vStr) {
        cin >> i;
    }
    int limit = min(n - 1, m - 1) / 2 + 1;
    debug(limit);
    for (int i = 0; i < limit; i++) {
        pair stCoor = {i, i};
        debug(i);
        vector<int> vRow;
        // go right
        for (int c = i; c < m - i; c++) {
            vRow.push_back(vStr[i][c] - '0');
        }
        // go down
        for (int r = i + 1; r < n - i; r++) {
            vRow.push_back(vStr[r][m - i - 1] - '0');
        }
        // go left
        for (int c = m - i - 2; c >= i; c--) {
            vRow.push_back(vStr[n - i - 1][c] - '0');
        }
        // go up
        for (int r = n - i - 2; r > i; r--) {
            vRow.push_back(vStr[r][i] - '0');
        }
        debug(vRow);
        int sz = vRow.size();
        for (int i = 0; i < sz; i++) {
            if (vRow[i] == 1 && vRow[(i + 1) % sz] == 5 && vRow[(i + 2) % sz] == 4 && vRow[(i + 3) % sz] == 3) {
                ans++;
            }
        }
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
