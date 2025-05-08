/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 05-05-2025 20:32:33
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

vector<int> getMaxPrefSuffArrSum(vector<int> v) {
    int n = v.size();
    vector<int> vPref(v), vSuff(v);
    int curMax = 0, maxArrSum = INT_MIN;
    for (auto c : v) {
        curMax = max(c, curMax + c);
        maxArrSum = max(maxArrSum, curMax);
    }
    int maxPref = v[0], maxSuff = v[n - 1];
    for (int i = 1; i < n; i++) {
        vPref[i] += vPref[i - 1];
        maxPref = max(maxPref, vPref[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        vSuff[i] += vSuff[i + 1];
        maxSuff = max(maxSuff, vSuff[i]);
    }
    debug(vPref, vSuff);
    return {maxPref, maxArrSum, maxSuff};
}

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<int> v(n);
    for (auto &i : v) {
        cin >> i;
    }
    vector<int> zeroIndexes;
    vector<vector<int>> vv, vMaxSums;
    vector<int> vTemp;
    for (int i = 0; i < n; i++) {
        if (str[i] == '1') {
            vTemp.push_back(v[i]);
        } else {
            if (i == 0) {
                zeroIndexes.push_back(i);
            } else if (str[i] != str[i - 1]) {
                zeroIndexes.push_back(i);
                if (vTemp.size()) {
                    vv.push_back(vTemp);
                    vTemp.clear();
                }
            }
        }
    }
    if (vTemp.size()) {
        vv.push_back(vTemp);
        vTemp.clear();
    }
    for (auto &i : vv) {
        auto x = getMaxPrefSuffArrSum(i);
        if (x[1] > k) {
            cout << "No";
            return;
        }
        vMaxSums.push_back(x);
    }
    debug(vMaxSums, zeroIndexes);
    if (zeroIndexes.size()) {
        v[zeroIndexes[0]] = k;
        if (zeroIndexes[0] == 0) {
            if (vMaxSums.size()) {
                v[zeroIndexes[0]] -= max(0LL, vMaxSums[0][0]);
            }
        } else if (zeroIndexes[0] == n - 1) {
            if (vMaxSums.size()) {
                v[zeroIndexes[0]] -= max(0LL, vMaxSums[0][2]);
            }
        } else {
            if (vMaxSums.size()) {
                v[zeroIndexes[0]] -= max(0LL, vMaxSums[0][2]);
            }
            if (vMaxSums.size() > 1) {
                v[zeroIndexes[0]] -= max(0LL, vMaxSums[1][0]);
            }
        }
        for (int i = 1; i < zeroIndexes.size(); i++) {
            v[zeroIndexes[i]] = -1e18;
        }
    }

    debug(v);

    if (getMaxPrefSuffArrSum(v)[1] != k) {
        cout << "No";
        return;
    }

    cout << "Yes" << endl;
    for (auto &i : v) {
        cout << i << " ";
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
