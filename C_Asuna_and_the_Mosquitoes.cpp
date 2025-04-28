/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 22-04-2025 15:45:44
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
    multiset<int> odd, even;
    for (auto &i : v) {
        cin >> i;
        if (i & 1) {
            odd.insert(i);
        } else {
            even.insert(i);
        }
    }
    debug(odd, even);
    while (odd.size() && even.size()) {
        if (even.size() == 1) {
            auto firstEven = even.begin();
            int mx = *firstEven;
            for (auto &i : odd) {
                mx += i - 1;
            }
            cout << mx + 1;
            return;
        } else {
            auto lastEven = prev(even.end());
            auto lastOdd = prev(odd.end());
            odd.insert(*lastEven + *lastOdd);
            odd.erase(lastOdd);
            even.erase(lastEven);
        }
    }
    ans = max(odd.size() ? *prev(odd.end()) : 0LL, even.size() ? *prev(even.end()) : 0LL);
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
