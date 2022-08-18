/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 08-03-2022 20:28:35
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
    int l, r, a;
    cin >> l >> r >> a;

    int div1 = l / a;
    int rem1 = l % a;
    int div2 = r / a;
    int rem2 = r % a;

    if(div1 == div2)
    {
        cout << rem2 + div2;
        return;
    }

    cout << max(div2 + rem2, div2 + a - 2);
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

