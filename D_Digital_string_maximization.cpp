/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 27-04-2025 15:00:00
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
    string str;
    cin >> str;
    n = str.length();
    vector<int> window;
    for (int i = 0; i < min(10LL, n); i++) {
        window.push_back(str[i] - '0');
    }
    debug(window);
    vector<int> vAns;
    for (int i = 0; i < n; i++) {
        int ind = 0;
        for (int i = 1; i < window.size(); i++) {
            if (window[ind] - ind < window[i] - i) {
                ind = i;
            }
        }
        vAns.push_back(window[ind] - ind);
        window[ind] = -1;
        vector<int> vTemp;
        for (int i = 0; i < window.size(); i++) {
            if (window[i] != -1) {
                vTemp.push_back(window[i]);
            }
        }
        if (i + 10 < n) {
            vTemp.push_back(str[i + 10] - '0');
        }
        debug(vTemp);
        window = vTemp;
    }
    for (auto &i : vAns) {
        cout << i;
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
