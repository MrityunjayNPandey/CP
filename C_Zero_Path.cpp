/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 21-06-2022 22:08:32
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
    cin >> n >> m;
    vector<vector<int>> vv(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> vv[i][j];
    // brute force of dp:
    // vector<vector<map<int, int>>> dpm(n + 1, vector<map<int, int>>(m + 1));
    // dpm[1][1][vv[1][1]]++;
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1;j <= m; j++)
    //     {
    //         if(i > 1)
    //             for(auto k : dpm[i - 1][j])
    //                 dpm[i][j][k.first + vv[i][j]]++;
    //         if(j > 1)
    //             for(auto k : dpm[i][j - 1])
    //                 dpm[i][j][k.first + vv[i][j]]++;
    //     debug(dpm[i][j], i, j);
    //     }
    // }
    // if(dpm[n][m][0] > 0)
    //     cout << "YES";
    // else
    //     cout << "NO";
    vector<vector<int>> dpmin(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dpmax(n + 1, vector<int>(m + 1, 0));
    dpmin[1][1] = vv[1][1];
    dpmax[1][1] = vv[1][1];
    for(int i = 2; i <= n; i++)
    {
        dpmax[i][1] = dpmax[i - 1][1] + vv[i][1];
        dpmin[i][1] = dpmin[i - 1][1] + vv[i][1];
    }
    for(int j = 2; j <= m; j++)
    {
        dpmax[1][j] = dpmax[1][j - 1] + vv[1][j];
        dpmin[1][j] = dpmin[1][j - 1] + vv[1][j];
    }
    debug(vv, dpmax, dpmin);
    for(int i = 2; i <= n; i++)
    {
        for(int j = 2; j <= m; j++)
        {
            if(i > 1 && j > 1)
            {
                dpmax[i][j] = max(dpmax[i - 1][j], dpmax[i][j - 1]) + vv[i][j];
                dpmin[i][j] = min(dpmin[i - 1][j], dpmin[i][j - 1]) + vv[i][j];
            }
        }
    }
    debug(dpmax, dpmin);
    if(dpmax[n][m] >= 0 && dpmin[n][m] <= 0 && (n + m) % 2)
    {
        cout << "YES";
    } else
        cout << "NO";
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

