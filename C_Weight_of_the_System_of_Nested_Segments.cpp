/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 18-05-2022 10:21:33
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
    vector<tuple<int, int, int>> vv1, vv;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        vv1.pb({ y, x , i + 1 });
    }
    sort(all(vv1));
    for(int i = 0; i < 2 * n; i++)
    {
        vv.pb({ get<1>(vv1[i]), get<0>(vv1[i]), get<2>(vv1[i]) });
        sum += get<1>(vv[i]);
    }
    sort(all(vv));
    cout << sum << endl;
    for(int i = 0; i < n; i++)
    {
        cout << get<2>(vv[i]) << " " << get<2>(vv[2 * n - i - 1]) << endl;
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

