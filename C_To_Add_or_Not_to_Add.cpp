/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 16-02-2022 17:37:22
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
    int a[MAX_N], n=0, k=0;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int res = 1, last = 0, best = a[0];
    int sum = a[0];
    for(int i = 1; i < n; i++)
    {
        sum += a[i];
        while(1LL * (i - last + 1) * a[i] - sum > k) 
        sum -= a[last++];
        if(res < i - last + 1) 
        res = i - last + 1, best = a[i];
    }
    cout << res << " " << best << endl;
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

