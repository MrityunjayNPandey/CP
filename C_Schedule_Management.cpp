/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 12-07-2022 10:36:39
**/
#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
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
    vector<int> v(m);
    map<int, int> mp;
    for(int i = 0; i < m; i++)
        cin >> v[i], mp[v[i]]++;
    int same = 0, diff = 0, diff1=0;
    while(mp.size())
    {
        if(k % 2 == 0)
        {
            if(diff)
                ans++;
            n += diff;
            diff = 0;
        } else
        {
            if(diff1)
                ans++;
            n += diff1;
            diff1 = 0;
        }
        k++;
        n += same;
        same = 0;
        for(auto& i : mp)
        {
            i.second--, same++;
            if(i.second == 0)
                mp.erase(i.first);
            if(same == n)
                break;
        }
        n -= same;
        if(same)
        ans++;
        for(auto& i : mp)
        {
            if(n >= i.second)
            {
                if(k % 2)
                    diff = i.second;
                else
                    diff1 = i.second;
                mp.erase(i.first);
            } else
            {
                if(k % 2)
                    diff = n;
                else
                    diff1 = n;
                break;
            }
        }
        n -= diff;
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
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

