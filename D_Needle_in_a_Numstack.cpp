/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 09-05-2025 16:24:11
 **/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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

/**
 * len > 250 + 2*k
 *
 * 1 2 3 4 1 2 3 1 2 3 4
 *
 * 1 2 3 4 . . . . . . . . . . 1 2 3 4
 *
 * 1 2 2 1 2 1
 *
 * 1 2 3 4 1 2 3 4 1 2 3 4
 *
 *
 * 1 2 1 2 1 2 1 2 1
 *
 * 1 2 3 4 1 2 3 4 1 2 3 4 1
 * 1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4
 */

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    vector<int> pref(k), suff(k);
    if (n == 2 * k) {
        cout << "! " << k << " " << k;
        return;
    }
    for (int i = 0; i < k; i++) {
        int x;
        cout << "? " << i + 1 << endl;
        cin >> x;
        pref[i] = x;
        cout << "? " << n - k + i + 1 << endl;
        cin >> x;
        suff[(n + k + i) % k] = x;
        debug(i, (n + k + i) % k);
    }
    debug(pref, suff);
    int vLength = ((n + k - 1) / k) * k;
    debug(vLength);
    int ind = -1;
    for (int i = 0; i < k; i++) {
        if (pref[i] != suff[i]) {
            ind = i;
            break;
        }
    }
    debug(ind);
    if (ind == -1) {
        cout << "! " << -1;
        return;
    }
    int l = 1, r = vLength / k - 2;
    int firstLast = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        debug(mid, (mid * k) + ind + 1);
        cout << "? " << (mid * k) + ind + 1 << endl;
        int x;
        cin >> x;
        debug(x);
        if (x == pref[ind]) {
            l = mid + 1;
            firstLast = mid;
        } else {
            r = mid - 1;
        }
    }
    debug(firstLast);
    vector<int> vNew;
    if (firstLast == 0) {
        int st = k;
        int en = (firstLast + 1) * k + ind;
        for (int i = st; i < en; i++) {
            cout << "? " << i + 1 << endl;
            int x;
            cin >> x;
            vNew.push_back(x);
        }
    } else {
        
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
