/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 15-04-2022 11:45:34
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

const int N = 1e5 + 4;
int a[N], d[4001][4001];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int ans = 0, g = 0;
    for(int i = 1;i <= n;i++)
    {
        g = 0;
        for(int j = 0;j < i;j++)
        {
            d[i][j] = d[j][g] + 1;
            if(a[i] == a[j]) g = j;
            ans = max(ans, d[i][j]);
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
        int Test = 1;
    // cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

