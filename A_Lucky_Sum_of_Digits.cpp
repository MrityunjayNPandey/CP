// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9+7; const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve()
{
    int n = 0, k = 0, ans = 0, ans1=0;
    cin >> n;
    int i = 0;
    while (i <= n && ans1 > -1)
    {
        k = n / 4;
        ans1 = n - (i * 4);
        if (ans1 % 7 == 0)
        {
            debug(ans1);
            for (int j = 0; j < i; j++)
                cout << 4;
            for (int j = 0; j < ans1 / 7; j++)
                cout << 7;
            return;
        }
        ans = n - (i * 7);
        if (ans % 7 == 0)
        {
            debug(ans);
            for (int j = 0; j < i; j++)
                cout << 7;
            for (int j = 0; j < ans / 4; j++)
                cout << 4;
            return;
        }
        i++;
    }
    cout << -1;
}

// clang-format off
int32_t main()
{
    ios;
    #ifdef SUBLIME
    free
    #endif
    int Test = 1;
    // cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef DEBUG
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}

