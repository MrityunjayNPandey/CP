/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 04-03-2022 02:14:17
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
{
    int n;
    cin >> n;
    string s;
    int x[n + 1] = { 0 }, y[n + 1] = { 0 }, C1 = 0, C2 = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> s;
        s = 'E' + s;
        for(int j = 1; j <= n; ++j)
        {
            if(s[j] == '.')
            {
                if(!y[j])
                {
                    y[j] = i;
                    ++C1;
                }
                if(!x[i])
                {
                    x[i] = j;
                    ++C2;
                }
            }
        }
    }
    if(C1 == n)
    {
        for(int i = 1; i <= n; ++i)
        {
            cout << y[i] << " " << i << endl;
        }
    } else if(C2 == n)
    {
        for(int i = 1;i <= n; ++i)
        {
            cout << i << " " << x[i] << endl;
        }
    } else
    {
        cout << -1;
    }
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

