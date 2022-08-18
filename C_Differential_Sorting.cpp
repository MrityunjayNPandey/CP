/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 20-02-2022 21:26:33
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
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.pb(x);
    }
    int l1 = v[n - 1], l2 = v[n - 2];
    bool flag = 1;
    for(int i = 0; i < n - 1; i++)
    {
        if(v[i] > v[i + 1])
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        cout << 0 << endl;
        return;
    }
    if(l2 - l1 <= l2 && l2 <= l1)
    {
        cout << n - 2 << endl;
        for(int i = 0; i < n - 2; i++)
        {
            cout << i + 1 << " " << n - 1 << " " << n << endl;
        }
        return;
    }
    cout << -1 << endl;
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

