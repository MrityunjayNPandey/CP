/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 20-05-2022 16:27:37
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
    cin >> n >> m;
    k = m;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> p(v);
    debug(p, v)
        int x = 0;
    for(int i = 1; i < n; i++)
    {
        if(k--)
            x++;
        v[i] += x;
    }
    debug(v);
    vector<tuple<int, int, int>> vp;
    for(int i = 0; i < n; i++)
    {
        vp.pb({ v[i], i , p[i] });
    }
    sort(all(vp));
    vector<pair<int, int>> p1;
    debug(n, k);
    for(int i = 0; i < n - m; i++)
    {
        p1.pb({ get<1>(vp[i]), get<2>(vp[i]) });
    }
    sort(all(p1));
    cnt = 0;
    if(p1.size())
    {
        cnt += p1[0].first;
        sum += p1[0].second + cnt;
    }
    debug(p1);
    for(int i = 1; i < p1.size(); i++)
    {
        cnt += p1[i].first - p1[i - 1].first - 1;
        sum += p1[i].second + cnt;
        debug(sum)
    }
    cout << sum;
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

