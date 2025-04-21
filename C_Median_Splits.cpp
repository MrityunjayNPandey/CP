/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 21-04-2025 21:35:03
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
int I = 0, Test = 1;

bool isFirstTwoPossible(auto &pref) {
    int n = pref.size();
    int mx = MAX_N;
    for (auto &i : pref) {
        if (i <= 0) {
            if (mx <= 0) {
                if (i <= mx) {
                    return true;
                } else {
                    mx = max(mx, i);
                }
            } else {
                mx = i;
            }
        }
    }
    return false;
}

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) {
        cin >> i;
    }
    for (int i = 0; i < n; i++) {
        if (v[i] <= k) {
            v[i] = -1;
        } else {
            v[i] = 1;
        }
    }
    vector<int> pref(n), suff(n);
    for (int i = 0; i < n; i++) {
        pref[i] += (i > 0 ? pref[i - 1] : 0) + v[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        suff[i] += (i < n - 1 ? suff[i + 1] : 0) + v[i];
    }
    debug(v, pref, suff);

    vector<int> revSuff(suff);
    reverse(revSuff.begin(), revSuff.end());

    // first and last
    if (isFirstTwoPossible(pref) || isFirstTwoPossible(revSuff)) {
        cout << "YES" << endl;
        return;
    }

    // first and last
    bool firstPossible = false, lastPossible = false;
    for (int i = 0; i < n; i++) {
        int subSum = pref[i];
        suff[i] = MAX_N;
        if (subSum <= 0) {
            firstPossible = true;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int subSum = suff[i];
        if (subSum <= 0) {
            lastPossible = true;
            break;
        }
    }
    if (firstPossible && lastPossible) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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
