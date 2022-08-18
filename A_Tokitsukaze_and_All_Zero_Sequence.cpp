/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 16-05-2022 21:37:46
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
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(v[i] != 0)
            cnt++;
        if(v[i] == 0)
            m++;
    }
    sort(all(v));
    if(!cnt)
    {
        cout << 0;
        return;
    }
    if(m)
    {
        cout << n - m;
        return;
    } else
    {
        for(int i = 0; i < n - 1; i++)
        {
            if(v[i] == v[i + 1])
            {
                m++;
            }
            if(m)
            {
                cout << n - m + 1;
                return;
            }
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(v[i] != v[i + 1])
            {
                v[i] = min(v[i], v[i + 1]);
                v[i + 1] = min(v[i], v[i + 1]);
            }
        }
        cout << n - m + 1;

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

