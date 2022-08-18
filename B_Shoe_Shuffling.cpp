/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 31-05-2022 20:16:00
**/
#include <bits/stdc++.h>
using namespace std;
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
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<pair<int, int>> v;
    map<int, int> mp;
    map<int, vector<int>> mpt;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.pb({ x, i });
        mpt[x].pb(i);
        mp[x]++;
    }
    for(auto i : mp)
    {
        if(i.second < 2)
        {
            cout << -1;
            return;
        }
    }
    vector<int> vans(n);
    sort(all(v));
    for(auto i : mpt)
    {
        vector<int> vt;
        int temp, temp1;
        int p1 = 0;
        for(auto j : i.second)
        {
            debug(j);
            if(!p1)
                temp = j, p1++;
            else
                vt.pb(j);
        }
        debug(temp, vt)
            temp1 = temp;
        for(auto p : vt)
        {
            vans[temp] = p;
            temp = p;
        }
        vans[temp] = temp1;
    }
    for(int i = 0; i < n; i++)
        cout << vans[i] + 1 << " ";
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

