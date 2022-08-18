/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 14-06-2022 22:04:17
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
#define LOG(n) 31 - __builtin_clz(n)
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
#define int long long

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    map<int, pair<int, int>> mp;
    mp[v[0]] = { 0, 0 };
    for(int i = 1; i < n; i++)
    {
        v[i] += v[i - 1];
        if(!mp.count(v[i]))
        {
            mp[v[i]] = { i, i };
        } else
        {
            mp[v[i]].second = i;
        }
    }
    debug(mp);
    if(v[n - 1] <= m)
    {
        if(v[n - 1] == m)
        cout << 0;
        else
        cout << -1;
        return;
    }
    for(auto i : mp)
    {
        if(mp.count(m + i.first))
        {
            int p = mp[m + i.first].second - mp[i.first].first;
            if(i.first == 0) p++;
            ans = max(ans, p);
            debug(ans)
        }
    }
    cout << n - ans;
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

