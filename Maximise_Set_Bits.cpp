/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 08-06-2022 21:11:50
**/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define print(x)
#define dclear(x)
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
const long long mod = 998244353; const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7;
#define int long long

vector<int> vp;

void pref()
{
    int x = 1, p = 1, t = 0;
    vp.pb(1);
    while(t <= 32)
    {
        x <<= 1;
        p += x;
        t++;
        vp.pb(p);
    }
}

void solve()
{
    int k = 0, ans = 0, cnt = 0, sum = 0;
    double n, m;
    cin >> n >> k;
    int x = (k / n);
    debug(x);
    int p1 = 0;
    {
        auto t = lower_bound(vp.begin(), vp.end(), x);
        debug(x, k / (*t));
        if(k / (*t) >= n)
        {
            p1 = n - 1;
        } else
        {
            p1 = k / (*t);
        }
        debug(*t);
        ans += (p1) * (__builtin_popcount(*t));
        debug(ans);
        ans += __builtin_popcount(max(k - (*t * (p1)), 0LL));
        debug(ans, k - (*t * p1));
    }
    int ans1=ans;
    ans=0;
    {
        auto t = upper_bound(vp.begin(), vp.end(), x);
        debug(x, k / (*t));
        if(k / (*t) >= n)
        {
            p1 = n - 1;
        } else
        {
            p1 = k / (*t);
        }
        debug(*t);
        ans += (p1) * (__builtin_popcount(*t));
        debug(ans);
        ans += __builtin_popcount(max(k - (*t * (p1)), 0LL));
        debug(ans, k - (*t * p1));
    }
    cout << max(ans, ans1);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    pref();
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

