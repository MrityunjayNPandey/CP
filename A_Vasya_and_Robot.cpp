/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 19-02-2022 12:30:53
**/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define dclear()
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
int I;

void solve()
{
    int  n, l, r, ql, qr, k = 0, k1 = 1e9;
    int a[100001];
    int i, j;
    cin >> n >> l >> r >> ql >> qr;
    a[0] = 0;
    for(i = 1;i <= n;i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for(i = 0;i <= n;i++)
    {
        k = (a[i] * l + (a[n] - a[i]) * r);
        if(i > n - i)
            k += (2 * i - n - 1) * ql;
        if(i < n - i)
            k += (n - 2 * i - 1) * qr;
        k1 = min(k1, k);
    }
    cout << k1 << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    // cin >> Test;
    for(I = 1; I <= Test; I++)
    {
#ifdef DEBUG
        clog << "-------" << I << "-------" << endl;dclear();
#endif
        solve();
        cout << endl;
    }
}

