/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 11-03-2022 20:09:53
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
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    if((n - 1) % 3 == 0)
    {
        while(n > 0)
        {
            if(k % 2 == 0)
            {
                cout << 1;
                n--;
            } else
            {
                cout << 2;
                n -= 2;
            }
            k++;
        }
    } else
    {
        while(n > 0)
        {
            if(k % 2 == 0)
            {
                cout << 2;
                n -= 2;
            } else
            {
                cout << 1;
                n--;
            }
            k++;
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
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

