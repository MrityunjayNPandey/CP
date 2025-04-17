/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 12-03-2025 15:29:50
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
#define free                                                                   \
    freopen("input.txt", "r", stdin);                                          \
    freopen("output.txt", "w", stdout);                                        \
    freopen("error.txt", "w", stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_map;
#define int long long

int getServingPeople(vector<int> &p, vector<int> &x, int check) {
    int n = p.size();
    int m = x.size();

    int peopleServed = 0;

    for (int i = 0; i < n; i++) {
        int buildingX = i * 100;

        auto it = lower_bound(x.begin(), x.end(), buildingX);

        int diff = INT_MAX;
        if (it == x.end()) {
            diff = buildingX - *prev(it);
        } else {
            diff = min(diff, *it - buildingX);
            if (it != x.begin()) {
                diff = min(diff, buildingX - *prev(it));
            }
        }

        int fastDist = abs(buildingX - check);

        if (diff > fastDist) {
            peopleServed += p[i];
        }
    }

    return peopleServed;
}

void solve() {
    int n = 0, m = 0, ans = 0;
    cin >> n >> m;
    vector<int> p(n), x(m);
    for (auto &i : p) {
        cin >> i;
    }
    for (auto &i : x) {
        cin >> i;
    }
    int l = 0, r = 100 * n;

    while (l <= r) {
        int mid = (l + r) / 2;

        int left = getServingPeople(p, x, mid - 1);
        int middle = getServingPeople(p, x, mid);
        int right = getServingPeople(p, x, mid + 1);

        debug(left, middle, right);

        if (middle >= left && middle >= right) {
            ans = middle;
            break;
        }

        if (right > left) {
            l = mid + 1;
        } else if (left > right) {
            r = mid - 1;
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
        int Test = 1;
    // cin >> Test;
    for (int I = 1; I <= Test; I++) {
        dclear(I);
        solve();
        cout << endl;
    }
}
