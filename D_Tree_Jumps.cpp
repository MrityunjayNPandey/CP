/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 03-05-2025 00:13:00
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

/**
 *      1
 *    2
 *  3  4
 * 5
 */

int calcRes(int x, auto &nodesAtLevel, auto &adjList, auto &levelOf) {
    int res = 1;
    debug(x);
    for (int &i : adjList[x]) {
        int val = calcRes(i, nodesAtLevel, adjList, levelOf);
        debug(val);
        (res += val) %= mod;
    }
    if (levelOf[x] > 2) (res *= nodesAtLevel[levelOf[x] - 1] - 1) %= mod;
    return res;
};

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    map<int, int> nodesAtLevel, levelOf;
    nodesAtLevel[1] = 1;
    levelOf[1] = 1;
    vector<int> v(n - 1);
    map<int, vector<int>> adjList;
    for (int i = 0; i < n - 1; i++) {
        cin >> v[i];
        levelOf[i + 2] = levelOf[v[i]] + 1;
        nodesAtLevel[levelOf[i + 2]]++;
        adjList[v[i]].push_back(i + 2);
    }

    debug(nodesAtLevel, adjList, levelOf);

    cout << calcRes(1, nodesAtLevel, adjList, levelOf);
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
