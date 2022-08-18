/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 27-03-2022 21:34:24
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

int l, r, ans, numone1[22], numone2[22], numzero1[22], numzero2[22];

void func1(int x)
{
    int count = 0;
    for(int i = 0; i <= 18; i++)
    {
        if(x % 2) numone1[i]++;
        else    numzero1[i]++;
        x /= 2;
    }
}

void func2(int x)
{
    int count = 0;
    for(int i = 0; i <= 18; i++)
    {
        if(x % 2) numone2[i]++;
        else    numzero2[i]++;
        x /= 2;
    }
}

void solve()
{
    memset(numzero1, 0LL, sizeof(numzero1));
    memset(numzero2, 0LL, sizeof(numzero2));
    memset(numone1, 0LL, sizeof(numone1));
    memset(numone2, 0LL, sizeof(numone2));
    cin >> l >> r;
    for(int i = l; i <= r; i++)
        func1(i);
    for(int i = l; i <= r; i++)
    {
        int x;
        cin >> x;
        func2(x);
    }
    ans = 0;
    int y = 1;
    for(int i = 0; i <= 20; i++)
    {
        if(numone1[i] != numone2[i] || numzero1[i] != numzero2[i])  ans += y;
        y *= 2;
    }
    cout << ans;
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

