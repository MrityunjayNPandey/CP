/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 24-07-2022 21:38:16
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
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
#define int long long

void solve()
{
    int n = 0, m = 0, k = 0, cnt = 0, ans = 0, sum = 0;
    cin >> n >> m;
    vector<int> v(n);
    map<int, vector<int>> adj_list;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    ans = INF;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj_list[x].pb(y);
        adj_list[y].pb(x);
        ans = min(ans, v[x - 1] + v[y - 1]);
    }
    if(m % 2 == 0)
    {
        cout << 0;
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(adj_list[i].size() % 2 == 1)
            ans = min(ans, v[i - 1]);
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

