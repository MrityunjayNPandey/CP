/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 02-05-2025 13:05:42
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
    int x;
    cin >> n >> x;
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(i);
    }
    debug(st);
    vector<int> v(n);
    v[n - 1] = st.find(x) == st.end() ? *prev(st.end()) : x;
    debug(v);
    st.erase(v[n - 1]);
    for (int i = 0; i < n - 1; i++) {
        v[i] = *st.begin();
        st.erase(v[i]);
    }
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
