/**
 * not clear, do it again
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 18-02-2022 19:42:30
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

void solve()
{
    int inv[1000002];
    int a, b, n;
    cin >> a >> b >> n;
    inv[1] = 1;
    for(int i = 2;i < 1000002;i++)
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;//calculating inv for every no. 
    int ans = 0, now = 1;
    for(int i = 0;i <= n;i++)
    {
        int d = i * a + (n - i) * b;
        bool ok = true;
        while(d)
        {
            if(d % 10 != a && d % 10 != b)ok = false;
            d /= 10;
        }
        if(ok)ans = (ans + now) % MOD;
        now = now * (n - i) % MOD * inv[i + 1] % MOD;
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
    for(int i = 1; i <= Test; i++)
    {
#ifdef DEBUG
        clog << "-------" << i << "-------" << endl;dclear();
#endif
        solve();
        cout << endl;
    }
}

