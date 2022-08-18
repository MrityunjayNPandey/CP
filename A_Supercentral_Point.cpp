/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 23-06-2022 21:53:48
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
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    m = n;
    vector<pair<int, int>> vp;
    int mina = INF;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vp.pb({ x, y });
        mina = min(mina, min(x, y));
    }
    debug(vp);
    for(int i = 0; i < n; i++)
    {
        vp[i].first -= mina;
        vp[i].second -= mina;
    }
    debug(mina, vp);
    n = 2000;
    vector<vector<int>> vv(n, vector<int>(n, 0)), vvxb(n, vector<int>(n, 0)), vvxr(n, vector<int>(n, 0)), vvyb(n, vector<int>(n, 0)), vvyr(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++)
    {
        vv[vp[i].first][vp[i].second]++;
    }
    for(int i = 0; i < n; i++)
    {
        k = 0;
        for(int j = 0; j < n; j++)
        {
            if(vv[i][j] > 0)
            {
                vvxb[i][j] = ++k;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        k = 0;
        for(int j = n - 1; j >= 0; j--)
        {
            if(vv[i][j] > 0)
            {
                vvxr[i][j] = ++k;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        k = 0;
        for(int j = 0; j < n; j++)
        {
            if(vv[j][i] > 0)
            {
                vvyb[j][i] = ++k;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        k = 0;
        for(int j = n - 1; j >= 0; j--)
        {
            if(vv[j][i] > 0)
            {
                vvyr[j][i] = ++k;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(vvxb[i][j] > 1 && vvxr[i][j] > 1 && vvyb[i][j] > 1 && vvyr[i][j] > 1)
                ans++;
        }
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
    // cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

