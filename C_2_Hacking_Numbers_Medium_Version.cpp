/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 17-05-2025 21:26:33
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
 *
 * 0 0
 * 0 1
 * 0 2
 * 0 3
 * 0 4
 * 0 5
 * 0 6 ....
 *
 *
 *
 */

void sumDigits() {
    int x;
    cout << "digit" << endl;
    cin >> x;
}

int diff(int p) {
    int x;
    cout << "add " << -p << endl;
    cin >> x;
    return x;
}

int add(int p) {
    int x;
    cout << "add " << p << endl;
    cin >> x;
    return x;
}

int mult(int p) {
    int x;
    cout << "mul " << p << endl;
    cin >> x;
    return x;
}

void finaliseTC() {
    int x;
    cout << "!" << endl;
    cin >> x;
}

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    debug(n);
    mult(9);
    sumDigits();
    sumDigits();
    add(n - 9);
    finaliseTC();
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
