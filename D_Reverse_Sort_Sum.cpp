/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 17-04-2022 22:07:00
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
    int n;
    cin >> n;
    vector<int> v(n), def(n), res(n);
    int sum = 0;
    for(auto& x : v)
    {
        cin >> x;
        sum += x;
    }
    int p = sum / n, temp = 0;
    for(int i = n - 1; i > -1;i--)
    {
        temp -= def[i];
        if(p > 0)
        {
            temp++;
            if(i - p >= 0)def[i - p]++;
        }
        v[i] -= temp;
        if(p > 0 && v[i] == i)
            res[i] = 1, --p;
    }
    for(auto i : res)
        cout << i << " ";
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

