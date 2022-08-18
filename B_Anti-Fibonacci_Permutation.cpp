/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 22-02-2022 20:15:21
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
    vector<int> v;
    if(n == 3)
    {
        cout << "3 2 1" << endl;
        cout << "1 3 2" << endl;
        cout << "3 1 2" << endl;
        return;
    } else
    {
        for(int i = n; i > 0; i--)
        {
            v.pb(i);
        }
    }
    for(int i = 0; i < n; i++)
    {
        int x = v[0];
        for(int j = 1; j < n; j++)
        {
            v[j - 1] = v[j];
            cout << v[j - 1] << " ";
        }
        v[n - 1] = x;
        cout << x << endl;
    }
    debug(v);
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
        // cout << endl;
    }
}

