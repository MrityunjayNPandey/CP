/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 19-02-2022 02:17:05
**/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define dclear()
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
int I;

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> v, v1;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.pb(x);
    }
    sort(all(v));
    if(v[n - 1] == 1)
    {
        for(int i = 0; i < n - 1; i++)
        {
            cout << v[i]<<" ";
        }
        cout << 2;
        return;
    }
    v1.pb(1);
    for(int i = 0; i < n - 1; i++)
    {
        v1.pb(v[i]);
    }
    for(int i = 0; i < n; i++)
        cout << v1[i] << " ";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    // cin >> Test;
    for(I = 1; I <= Test; I++)
    {
#ifdef DEBUG
        clog << "-------" << I << "-------" << endl;dclear();
#endif
        solve();
        cout << endl;
    }
}

