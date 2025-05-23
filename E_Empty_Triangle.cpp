/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 12-05-2025 23:38:16
 **/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
 *.   .
 *  .
 *  .
 *  .
 *  .
 *  .
 *  .
 *  .
 *  .
 *  .
 *  .
 *  .
 *  .
 *  .
 */

void solve() {
    int n = 0, m = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    int i = 1, j = 2, k = 3;
    int p = 100;
    while (p--) {
        cout << "?" << " " << i << " " << j << " " << k << endl;
        int x;
        cin >> x;
        if (x == 0) {
            cout << "!" << " " << i << " " << j << " " << k << endl;
            return;
        }
        int p = rand() % 3 + 1;
        if (p == 1) {
            i = x;
        } else if (p == 2) {
            j = x;
        } else {
            k = x;
        }
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
