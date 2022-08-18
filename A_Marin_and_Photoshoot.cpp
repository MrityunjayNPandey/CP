/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 27-03-2022 20:15:50
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
    string str;
    cin >> str;
    // if(n > 2)
    //     for(int i = 1; i < str.length() - 1; i++)
    //     {
    //         if(str[i - 1] == '0' && str[i] == '1' && str[i + 1] == '0')
    //             ans++;
    //         if(str[i] == '0' && str[i - 1] == '0')
    //             ans += 2;
    //         if(i == n - 2)
    //             if(str[i] == '0' && str[i + 1] == '0')
    //                 ans += 2;
    //     }
    // if(n == 1)
    //     if(str[0] == '0')
    //         ans++;
    // if(n == 2)
    //     if(str[0] == '0' && str[1] == '0')
    //         ans += 2;
    for(int i = 0; i < n - 1; i++)
    {
        if(str[i] == '0' && str[i + 1] == '0')
            ans += 2;
    }
    for(int i = 0; i < n - 2; i++)
    {
        if(str[i] == '0' && str[i + 1] == '1' && str[i + 2] == '0')
            ans += 1;
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
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

