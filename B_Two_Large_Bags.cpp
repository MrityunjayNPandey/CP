/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 02-05-2025 17:25:34
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
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    int maxNum = 0;
    for (auto &i : v) {
        cin >> i;
        mp[i]++;
        maxNum = max(maxNum, i);
    }
    int toNeed = 0;
    while (mp.size()) {
        auto [l, r] = *prev(mp.end());

        if (toNeed && (l + 1) != maxNum) {
            toNeed += (maxNum - l - 1) * 2;
            debug(toNeed, (maxNum - l - 1));
        }

        int toSubtract = 0;
        if (r > 2 && toNeed) {
            toSubtract = min(r - 2, toNeed);
            toNeed -= toSubtract;
        }
        toNeed += (r - toSubtract) & 1;
        debug(mp, toNeed);

        if (toNeed) {
            maxNum = l;
        }

        mp.erase(prev(mp.end()));
    }
    debug(toNeed);
    if (toNeed) {
        cout << "No";
    } else {
        cout << "Yes";
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
