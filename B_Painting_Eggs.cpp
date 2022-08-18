/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 26-05-2022 14:47:51
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
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.pb({ x, y });
    }
    sort(all(v));
    debug(v);
    int a = 0, g = 0;
    string str;
    for(int i = 0; i < n; i++)
    {
        if(a > g && abs(g + v[i].second - a) <= 500)
        {
            g += v[i].second;
            str += 'G';
        } else if(g > a && abs(g - a - v[i].first) <= 500)
        {
            a += v[i].first;
            str += 'A';
        } else
        {
            if(v[i].first >= v[i].second)
                g += v[i].second, str += 'G';
            else
                a += v[i].first, str += 'A';
        }
    }
    debug(str);
    debug(g, a);
    if(abs(g - a) > 500)
    {
        cout << -1;
        return;
    }
    cout << str;
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

