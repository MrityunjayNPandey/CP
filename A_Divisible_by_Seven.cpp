/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 08-03-2022 19:48:51
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
const long long INF = 1ll << 32; const long long MAX_N = 1e7 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long

void solve()
{
    int n = 0, m = 0, k = 1, ans = 0, cnt = 0, sum = 0;
    string s;
    cin >> s;
    while(true)
    {
        n = 0;
        for(int i = 0;i < s.size();i++)
        {
            n *= 10;
            n += (s[i] - '0');
            n %= 7;
        }
        if(n == 0)
        {
            cout << s;
            return;
        }
        next_permutation(s.begin(), s.end());
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
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

