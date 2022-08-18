/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 07-06-2022 20:49:22
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

void showq(queue<int> gq)
{
    queue<int> g = gq;
    while(!g.empty())
    {
        clog << g.front() << " ";
        g.pop();
    }
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> v(n), v1(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    vector<int> vans;
    for(int i = 0; i < n - 1; i++)
    {
        vans.pb(v1[i] - v[i]);
        if(v[i + 1] < v1[i]) v[i + 1] = v1[i];
    }
    vans.pb(v1[n - 1] - v[n - 1]);
    for(int i = 0; i < n; i++)
        cout << vans[i] << " ";
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

