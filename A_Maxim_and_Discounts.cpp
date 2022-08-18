/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 04-03-2022 13:09:59
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
    int n, m, ans = 0;
    cin >> m;
    int t = 0, mn = 1e5 + 5;
    for(int i = 0;i < m;i++)
    {
        int x; cin >> x; mn = min(mn, x);
    }
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++)cin >> a[i];
    sort(a, a + n);
    for(int i = n - 1;i >= 0;i--)
    {
        t++;
        if(t <= mn)ans += a[i];
        else if(t == mn + 2)t = 0;
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
    // cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

