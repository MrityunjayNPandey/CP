/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 20-03-2022 09:45:07
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
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        sum += (str[i] - '0');
    }
    m = ((sum + 8) / 9) * 9 - sum;
    for(int i = 0; i < str.length(); i++)
    {
        if(k || (str[i] - '0') <= m || (m == 0 && i == 0))
        {
            cout << str[i];
        } else
        {
            cout << m << str[i];
            debug("00989")
                k++;
        }
    }
    if(k == 0)
        cout << m;
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
        cout << "Case #" << I << ": ";
        solve();
        cout << endl;
    }
}

