/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 25-04-2025 16:25:14
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

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) {
        cin >> i;
    }
    vector<pair<int, int>> vp;
    if (v[n - 1] == 0) {
        vp.push_back({n - 1, n});
        n--;
        v[n - 1] = 1;
    }
    // find the 1st 0
    int first0 = -1, num1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0 && first0 == -1) {
            first0 = i;
        }
        debug(v[i]); 
    }
    if (first0 == -1) {
        vp.push_back({1, n});
    } else {
        vp.push_back({first0 + 1, first0 + 2});
        int diff = 1;
        int currIndex = first0 + 2;
        while (currIndex < n) {
            for (int i = currIndex; i < n; i++) {
                currIndex = i + 1;
                if (v[i] == 0) {
                    vp.push_back({first0 + 1, i + 1 - diff});
                    diff = i - first0;
                    break;
                }
            }
        }
        vp.push_back({1, currIndex - diff});
    }

    cout << vp.size() << endl;
    for (auto &[l, r] : vp) {
        cout << l << " " << r << endl;
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
