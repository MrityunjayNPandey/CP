/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 28-04-2025 12:33:33
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
    int L = 0;
    cin >> n >> m >> L;
    vector<pair<int, int>> vp(n);
    vector<pair<int, int>> vX(m);
    for (auto &[l, r] : vp) {
        cin >> l >> r;
    }
    for (auto &[l, r] : vX) {
        cin >> l >> r;
    }
    debug(vp, vX);
    int initX = 1, jumpSz = 1;
    multiset<int> mltst;
    for (auto &[l, r] : vp) {
        int left = 0, right = m - 1;
        int firstInd = -1, lastInd = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (vX[mid].first > l - 1) {
                right = mid - 1;
            } else if (vX[mid].first < initX) {
                left = mid + 1;
            } else {
                firstInd = mid;
                right = mid - 1;
            }
        }
        left = 0, right = m - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (vX[mid].first > l - 1) {
                right = mid - 1;
            } else if (vX[mid].first < initX) {
                left = mid + 1;
            } else {
                lastInd = mid;
                left = mid + 1;
            }
        }
        initX = r + 1;
        debug(firstInd, lastInd);
        for (int i = firstInd; i <= lastInd && i > -1; i++) {
            mltst.insert(vX[i].second);
        }
        debug(mltst);
        int hurdleSize = r - l + 1;
        while ((hurdleSize + 1) > jumpSz && mltst.size()) {
            jumpSz += *prev(mltst.end());
            mltst.erase(prev(mltst.end()));
            ans++;
        }
        debug(mltst);
        if ((hurdleSize + 1) > jumpSz) {
            cout << -1;
            return;
        }
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
