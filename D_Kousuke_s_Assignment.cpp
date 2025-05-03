/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 03-05-2025 19:15:12
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

bool comp(pair<int, int> &a, pair<int, int> &b) { return (a.second < b.second); }

vector<pair<int, int>> getDisjoint(vector<pair<int, int>> &arr) {
    // Sort the array of intervals
    // based on second element
    sort(arr.begin(), arr.end(), comp);

    // Stores the end point of the last
    // interval included in the maximal
    int end = -1;

    // Stores the maximal disjoint set
    vector<pair<int, int>> ans;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].first > end) {
            ans.push_back(arr[i]);
            end = arr[i].second;
        }
    }

    return ans;
}

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> v(n), vPref(n + 1);
    for (auto &i : v) {
        cin >> i;
    }
    for (int i = 0; i < n; i++) {
        vPref[i + 1] += vPref[i] + v[i];
    }
    debug(vPref);
    map<int, vector<int>> mp;
    for (int i = 0; i < n + 1; i++) {
        mp[vPref[i]].push_back(i);
    }
    debug(mp);
    vector<pair<int, int>> vp;
    for (auto &[l, r] : mp) {
        for (int i = 1; i < r.size(); i++) {
            vp.push_back({r[i - 1], r[i] - 1});
        }
    }

    cout << getDisjoint(vp).size();
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
