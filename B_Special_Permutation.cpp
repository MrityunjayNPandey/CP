/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 11-04-2022 16:43:38
**/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
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
{//t2
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    int a, b;
    cin >> n >> a >> b;
    vector<int> v;
    map<int, int> mp;
    v.pb(a);
    mp[a]++;
    k = n;
    for(int i = 1; i < n / 2; i++)
    {
        if(k == b)
            k--;
        mp[k]++;
        v.pb(k--);
    }
    v.pb(b);
    mp[b]++;
    k = 1;
        for(int i = 1; i < n / 2; i++)
        {
            if(k == a)
                k++;    
            mp[k]++;
            v.pb(k++);
        }
    for(auto i : mp)
    {
        if(i.second > 1)
        {
            debug(v)
            cout << -1;
            return;
        }
    }
    for(auto i : v)
    {
        cout << i << " ";
    }
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

