/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 19-04-2025 15:57:09
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

bool cmp(pair<char, int>& a, pair<char, int>& b) { return a.second > b.second; }

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    string str;
    cin >> str;
    map<char, int> mp;
    for (int i = 0; i < n; i++) {
        mp[str[i]]++;
    }
    if (mp.size() == 1) {
        cout << str;
        return;
    }
    vector<pair<char, int>> vp;
    for (auto& [l, r] : mp) {
        vp.push_back({l, r});
    }
    sort(vp.begin(), vp.end(), cmp);
    debug(vp);
    auto& [x, _p] = vp.front();
    auto& [y, _x] = vp.back();
    debug((char)x, (char)y);
    bool isAdded = false;
    for (int i = 0; i < n; i++) {
        if (str[i] == y && !isAdded) {
            str[i] = x;
            isAdded = true;
        }
    }
    cout << str;
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
