/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 08-06-2022 17:09:33
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

int powerModulo(long long x, unsigned int y, int p)
{
    int res = 1;     // Initialize result
    x = x % p; // Update x if it is more than or
                // equal to p
    if(x == 0) return 0; // In case x is divisible by p;
    while(y > 0)
    {
        // If y is odd, multiply x with result
        if(y & 1)
            res = (res * x) % p;
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    cout << powerModulo(n, k, MOD);
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

