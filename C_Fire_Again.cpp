/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 26-04-2022 21:56:59
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
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, MOD));
    cin >> k;
    vector<pair<int, int> > v1;
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        v1.pb({ x, y });
    }
    debug(v1)
        for(int i = 0; i < k; i++)
        {
            for(int x = 0; x < n; x++)
                for(int y = 0; y < m; y++)
                {
                    v[x][y] = min(v[x][y], (abs(v1[i].first - x - 1) + abs(v1[i].second - y - 1)));
                }
        }
    debug(v)
        int maxa = 0;
    pair<int, int> pi;
    for(int x = 0; x < n; x++)
        for(int y = 0; y < m; y++)
        {
            if(maxa < v[x][y])
            {
                maxa = v[x][y];
                pi = { x, y };
            }
        }
    cout << pi.first + 1 << " " << pi.second + 1;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    free
    int Test = 1;
// cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
    return 0;
}

