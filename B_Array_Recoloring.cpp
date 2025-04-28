/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 27-04-2025 12:01:55
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

// 100 90 80 70 50 60
// (7 1) (6 4)
// . . . . . . . . X X X X X . . . .
// 6
// x X x x . x . .  .  x X x
// 1 7 1 1 8 1 9 10 11 1 7 1
// . . . X . . . X . . . X . . . . X . . .
// . . . X . . . . X . . .

// 2, 3, 4, 5, 6,

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    vector<int> v(n);
    multiset<int> mltst, poss;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mltst.insert(v[i]);
    }
    if (k + 1 > 2) {
        int x = k + 1;
        while (x--) {
            auto lastElem = prev(mltst.end());
            ans += *lastElem;
            mltst.erase(lastElem);
        }
    } else {
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, max(v[i] + v[0], v[i] + v[n - 1]));
        }
        ans = max(ans, v[0] + v[n - 1]);
    }
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
