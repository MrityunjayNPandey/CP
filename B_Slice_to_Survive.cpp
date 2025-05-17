/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 17-05-2025 20:17:30
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

/**
 * 11
 *  5 9 8
 *  3 5 4
 *  2 3 2
 *  1 2 1
 *    1
 */

int getCuts(int x) {
    int cnt = 0;
    while (x > 1) {
        x = (x + 1) / 2;
        cnt++;
    }
    return cnt;
}

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    int a, b;
    cin >> n >> m >> a >> b;
    int x = min(a, n - a + 1);
    int y = min(b, m - b + 1);
    debug(x, y, n, m, a, b);
    int minXCuts = 1 + getCuts(x);
    int minYCuts = 1 + getCuts(y);
    int nCuts = getCuts(n);
    int mCuts = getCuts(m);
    cout << min(minXCuts + mCuts, minYCuts + nCuts);
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
