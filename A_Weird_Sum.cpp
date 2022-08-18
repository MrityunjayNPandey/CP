/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 24-06-2022 03:58:57
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

int t = 0;

bool sortbysec(const pair<int, int>& a, const pair<int, int>& b)
{
    return abs(t - a.second) < abs(t - b.second);
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<vector<int>> vv(n, vector<int>(m, 0));
    map<int, vector<pair<int, int>>> mp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> vv[i][j], mp[vv[i][j]].pb({ i, j });
    }
    vector<vector<pair<int, int>>> vv1;
    for(auto i : mp)
    {
        vector<pair<int, int>> temp;
        for(auto j : i.second)
        {
            temp.pb(j);
        }
        vv1.pb(temp);
    }
    debug(mp);
    for(auto i:vv1)
    {
      vector<int> vx, vy;
      for(auto j:i)
      {
        vx.pb(j.first),vy.pb(j.second);
      }
      sort(all(vx));
      sort(all(vy));
      for(int k=0; k<vx.size(); k++)
      {
        ans+=(2*k+1-vx.size())*vx[k];
      }
      for(int k=0; k<vy.size(); k++)
      {
        ans+=(2*k+1-vy.size())*vy[k];
      }
    }
    cout<<ans;
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