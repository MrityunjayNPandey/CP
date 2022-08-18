/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 02-05-2022 20:42:16
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

int nCr[1001][1001];

void pref()
{
    int n = 1000;
    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= i;j++)
        {
            if(j == 0 || j == i) nCr[i][j] = 1;
            else nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]);
        }
    }
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < t.length(); i++)
    {
        if(t[i] == 'a')
        {
            k++;
            break;
        }
    }
    if(k)
    {
        if(t.length() == 1)
        {
            cout << 1;
            return;
        }
        cout << -1;
        return;
    }
    for(int i = 1; i < s.length(); i++)
    {
        ans += nCr[s.length()][i];
        debug(ans)
    }
    cout << ans + 2;
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
        dclear(I);
        solve();
        cout << endl;
    }
}

