/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 20-03-2022 11:13:54
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

void pref()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0, l = 0, r = 0;
    for(int i = 1; i <= 100000; i++)
    {
        string str = to_string(i);
        int mult = 1, sum = 0;
        for(int i = 0; i < str.length(); i++)
        {
            sum += (str[i] - '0');
            mult *= (str[i] - '0');
        }
        if(i % 10 == 0)
            debug(i, ans);
        if(mult % sum == 0)
        {
            ans++;
        }
    }
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0, l = 0, r = 0;
    cin >> l >> r;
    for(int i = l; i <= r; i++)
    {
        string str = to_string(i);
        int mult = 1, sum = 0;
        for(int i = 0; i < str.length(); i++)
        {
            sum += (str[i] - '0');
            mult *= (str[i] - '0');
        }
        if(mult % sum == 0)
        {
            ans++;
            // debug(str);
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
        pref();
    int Test = 1;
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        cout << "Case #" << I << ": ";
        dclear(I);
        solve();
        cout << endl;
    }
}

