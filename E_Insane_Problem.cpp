/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 27-04-2025 18:09:42
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
    int l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    vector<int> nums;
    int x = 1;
    for (int i = 0; x <= 1e9; i++) {
        nums.push_back(x);
        x *= k;
    }
    debug(nums);
    for (auto &i : nums) {
        int l = l1, r = r1;
        // minimum valid x:
        int minX = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (i * mid > r2) {
                r = mid - 1;
            } else if (i * mid < l2) {
                l = mid + 1;
            } else {
                r = mid - 1;
                minX = mid;
            }
        }
        if (minX == -1) {
            continue;
        }
        // maximium valid x:
        int maxX = -1;
        l = l1, r = r1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (i * mid > r2) {
                r = mid - 1;
            } else if (i * mid < l2) {
                l = mid + 1;
            } else {
                l = mid + 1;
                maxX = mid;
            }
        }
        ans += maxX - minX + 1;
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
