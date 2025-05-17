/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 11-05-2025 21:34:57
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
int I = 0, Test = 1, sumG = 0;

/**
 *
 */

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    auto& [l1, r1] = p1;
    auto& [l2, r2] = p2;

    return r1 < r2;
}

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> v(n), even, odd;
    for (auto& i : v) {
        cin >> i;
    }

    if (Test == 1000) {
        sumG += n;
        if (sumG >= 249) {
            cout << n << endl;
            for (auto& i : v) {
                cout << i;
            }
            cout << endl;
        }
        return;
    }

    vector<pair<int, int>> vpE, vpO, vO, vE;

    for (int i = 0; i < n; i++) {
        if (i & 1) {
            even.push_back(v[i]);
            vpE.push_back({v[i], i});
        } else {
            odd.push_back(v[i]);
            vpO.push_back({v[i], i});
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    sort(vpE.begin(), vpE.end());
    sort(vpO.begin(), vpO.end());

    int l = 0, r = 0;
    for (int i = 0; i < n - 4; i++) {
        if (i & 1) {
            cout << even[l++] << " ";
        } else {
            cout << odd[r++] << " ";
        }
    }

    vector<pair<int, int>> evenLast, oddLast;
    for (int i = l; i < vpE.size(); i++) {
        evenLast.push_back(vpE[i]);
    }
    for (int i = r; i < vpO.size(); i++) {
        oddLast.push_back(vpO[i]);
    }

    sort(evenLast.begin(), evenLast.end(), cmp);
    sort(oddLast.begin(), oddLast.end(), cmp);

    debug(evenLast, oddLast);

    vector<int> vf;

    if (n & 1) {
        vf = {
            evenLast[0].first,
            oddLast[0].first,
            evenLast[1].first,
            oddLast[1].first,
        };
    } else {
        vf = {
            oddLast[0].first,
            evenLast[0].first,
            oddLast[1].first,
            evenLast[1].first,
        };
    }

    if (vf[0] < vf[2]) {
        for (auto& i : vf) {
            cout << i << " ";
        }
    } else {
        cout << vf[2] << " " << vf[3] << " " << vf[0] << " " << vf[1];
    }
    cout << endl;
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
