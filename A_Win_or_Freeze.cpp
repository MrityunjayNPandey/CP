/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 19-02-2022 18:30:36
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
    int n = 0, x1 = 0, x2 = 0;
    cin >> n;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            x1 = n / i;
            for(int j = 2; j * j <= x1; j++)
            {
                if(x1 % j == 0)
                {
                    cout << "1" << endl << i * j << endl;
                    return;
                }
            }
            cout << "2" << endl;
            return;
        }
    }
    cout << "1 " << endl << 0 << endl;
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

