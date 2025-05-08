/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 04-05-2025 15:56:18
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
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> mp;
    for (auto &i : v) {
        cin >> i;
        mp[i]++;
    }
    debug(mp);
    vector<pair<int, int>> vp;
    for (auto &[l, r] : mp) {
        vp.push_back({l, r});
    }
    debug(vp);
    for (int i = 0; i < vp.size() - 1; i++) {
        if (vp[i + 1].first == vp[i].first + 1) {
            vp[i + 1].second += vp[i].second;
        }
    }
    debug(vp);
    vector<pair<int, int>> vp1(vp);
    cnt = 1;
    ans = max(ans, vp[0].second);
    for (int i = 1; i < vp.size(); i++) {
        if (cnt == k) {
            if (i - k >= 0 && vp[i].first - vp1[i - k].first == k) {
                vp[i].second -= vp1[i - k].second;
            }
        } else {
            cnt++;
        }
        ans = max(ans, vp[i].second);
    }
    debug(vp);
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
