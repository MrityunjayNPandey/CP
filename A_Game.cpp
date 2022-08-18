/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 13-05-2022 01:50:25
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
    int n = 0, m = 0, k = 0, ans = 1, cnt = 0, sum = 0;
    cin >> n;
    vector<int> v(n);
    map<int, map<int, map<int, int>>> mp;
    map<int, int> mp1, mp2;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp1[v[i]]++;
    }
    int t = 1;
    vector<int> vis(n + 1), vis1(n + 1), vis2(n + 1);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x == 0)
        {
            mp2[v[i]] = i + 1;
            mp[v[i]][i + 1];
        }
        for(int j = 0; j < x; j++)
        {
            int p;
            cin >> p;
            mp[v[i]][i + 1][p]++;
        }
    }
    debug(mp2)
        k = n - 1;
    int k1 = n - 1, k2 = n - 1;
    if(n == 1)
    {
        cout << 1;
        return;
    }
    debug(mp);
    int x1 = 0;
    if(mp2[1] > 0)
    {
        x1++;
        t = 1;
        vis[mp2[t]] = 1;
        int px = t;
        while(k)
        {
            int tx1 = 0;
            for(auto i : mp[t])
            {
                debug(i.first, i.second);
                if(!vis[i.first])
                {
                    int p1 = 0;
                    for(auto j : i.second)
                    {
                        debug(j.second)
                            if(!vis[j.first])
                            {
                                p1++;
                                break;
                            }
                    }
                    if(!p1)
                    {
                        vis[i.first]++;
                        k--;
                        tx1++;
                        ans++;
                        debug(ans)
                    }
                }
            }
            if(tx1) t--;
            t++;
            if(k == 0)
                break;
            if(t == 4 || t == 0)
                t = 1;
            if(px != t)
                ans++;
            debug(ans, t)
                px = t;
        }
    }
    int ans1 = ans;
    if(!x1)
    {
        ans1 = INT_MAX;
    }
    ans = 1;
    int x2 = 0;
    if(mp2[2] > 0)
    {
        x2++;
        t = 2;
        vis1[mp2[t]] = 1;
        int px = t;
        while(k1)
        {
            int tx1 = 0;
            for(auto i : mp[t])
            {
                debug(i.first, i.second);
                if(!vis1[i.first])
                {
                    int p1 = 0;
                    for(auto j : i.second)
                    {
                        debug(j.second)
                            if(!vis1[j.first])
                            {
                                p1++;
                                break;
                            }
                    }
                    if(!p1)
                    {
                        vis1[i.first]++;
                        k1--;
                        tx1++;
                        ans++;
                        debug(ans)
                    }
                }
            }
            if(tx1) t--;
            t++;
            if(k1 == 0)
                break;
            if(t == 4 || t == 0)
                t = 1;
            if(px != t)
                ans++;
            debug(ans, t)
                px = t;
        }
    }
    int ans2 = ans;
    if(!x2)
    {
        ans2 = INT_MAX;
    }
    ans = 1;
    int x3 = 0;
    if(mp2[3] > 0)
    {
        x3++;
        t = 3;
        vis2[mp2[t]] = 1;
        int px = t;
        while(k2)
        {
            int tx1 = 0;
            for(auto i : mp[t])
            {
                if(!vis2[i.first])
                {
                    int p1 = 0;
                    for(auto j : i.second)
                    {
                        if(!vis2[j.first])
                        {
                            p1++;
                            break;
                        }
                    }
                    if(!p1)
                    {
                        vis2[i.first]++;
                        k2--;
                        tx1++;
                        ans++;
                    }
                }
            }
            if(tx1) t--;
            t++;
            if(k2 == 0)
                break;
            if(t == 4 || t == 0)
                t = 1;
            if(px != t)
                ans++;
            px = t;
        }
    }
    int ans3 = ans;
    if(!x3)
        ans3 = INT_MAX;
    debug(ans1, ans2, ans3)
        cout << min(ans1, min(ans2, ans3));
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

