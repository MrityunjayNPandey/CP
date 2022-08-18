/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 02-05-2022 22:02:01
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
    int a[n], p1[n], ans = LONG_LONG_MAX;
    debug(LONG_LONG_MAX, INF)
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(i)
        {
            int p3 = (a[i - 1] + a[i] + 2) / 3;
            if(i + 1 != n)
            {
                p3 = min(p3, max(a[i + 1], a[i - 1]));
            }
            ans = min(ans, p3);
        }
        p1[i] = (1 + a[i]) / 2;
    }
    sort(p1, p1 + n);
    cout << min(p1[1] + p1[0], ans);
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

