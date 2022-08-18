/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 16-02-2022 18:10:02
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
    int n;
    int ans;
    cin >> n;
    if(n == 2)
    {
        cout << 2 << endl; return;
    } else if(n == 1)
    {
        cout << 1 << endl; return;
    }
    int t = n * (n - 1) * (n - 2);
    int s = (n - 1) * (n - 2) * (n - 3);
    if(n % 2 == 1)
    {
        ans = t;
        cout << ans << endl;
        return;
    } else
    {
        if(n > 5 && n % 3 == 0)
        {
            ans = s;
            cout << ans << endl;
            return;
        } else if(n > 5)
        {
            ans = n * (n - 1) * (n - 3);
            cout << ans << endl;
            return;
        } else
        {
            ans = t / 2;
            cout << ans << endl;
            return;
        }
    }
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

