/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 11-05-2025 20:38:07
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

/**
 * 36
 *
 *
 * 3*3
 * 1 * 1 = 9
 * 1 * 2 = 6
 * 1 * 3 = 3
 * 2 * 1 = 6
 * 2 * 2 = 4
 * 2 * 3 = 2
 * 3 * 1 = 3
 * 3 * 2 = 2
 * 3 * 3 = 1
 */

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<vector<int>> vv(n, vector<int>(n, -1));
    int l = (n + 1) / 2 - 1, r = (n + 1) / 2 - 1;
    string dir = "RDLU";
    int x = 0;
    while (l < n && r < n && l >= 0 && r >= 0) {
        vv[l][r] = k;
        k++;
        if (dir[x % 4] == 'R') {
            if (r + 1 < n && vv[l][r + 1] != -1) {
                l--;
            } else {
                r++;
                x++;
            }
        } else if (dir[x % 4] == 'D') {
            if (l + 1 < n && vv[l + 1][r] != -1) {
                r++;
            } else {
                l++;
                x++;
            }
        } else if (dir[x % 4] == 'L') {
            if (r - 1 >= 0 && vv[l][r - 1] != -1) {
                l++;
            } else {
                r--;
                x++;
            }
        } else {
            if (l - 1 >= 0 && vv[l - 1][r] != -1) {
                r--;
            } else {
                l--;
                x++;
            }
        }
    }
    for (auto &i : vv) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
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
    }
}
