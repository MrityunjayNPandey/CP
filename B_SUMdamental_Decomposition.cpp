/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 01-05-2025 20:51:51
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
    cin >> n >> k;
    int xorv = k;
    int p = n - 1;
    vector<int> v;
    while (p-- && k) {
        int num = 1LL << LOG(k);
        sum += num;
        v.push_back(num);
        k -= num;
    }
    if (k) {
        v.push_back(k);
        sum += k;
    }
    if (((n - v.size()) & 1) == 0) {
        sum += n - v.size();
    } else {
        if (v.size() == 0) {
            if (n == 1) {
                cout << -1;
            } else {
                cout << n - 3 + 6;
            }
            return;
        }
        if (v.size()) {
            m = v.back();
        }
        int x = 0;
        int p = v.front();
        //first unwaqnted bit
        while (p) {
            if ((p & 1) == 0) {
                break;
            }
            x++;
            p /= 2;
        }
        int newElem = 1LL << x;
        if (n - v.size() >= 3 && (2 * newElem) > 6) {
            sum += n - v.size() - 3 + 6;
        } else {
            sum += n - v.size() - 1;
            sum += 2 * newElem;
        }
    }
    debug(v);
    cout << sum;
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
