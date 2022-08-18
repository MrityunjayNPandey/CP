/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 24-05-2022 22:55:29
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
    int  k = 0, ans = 0, cnt = 0, sum = 0, n = 0, m = 0;
    cin >> n >> m >> k;
    vector<vector<int>> vv(n, vector<int>(m, 0));
    vector<int> v;
    map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> vv[i][j];
            sum += vv[i][j];
            v.pb(vv[i][j]);
            mp[vv[i][j]]++;
        }
    }
    sort(all(v));
    debug(v);
    int ans1 = INT_MAX;
    if((m*n) % 2 == 0)
    {
        int mean = v[m*n / 2 - 1];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int p = abs(vv[i][j] - mean);
                debug(p, vv[i][j])
                    if(p % k == 0)
                        ans += p / k;
                    else
                    {
                        cout << -1;
                        return;
                    }
                debug(ans);
            }
        }
        ans1 = min(ans1, ans);
        ans = 0;
        mean = v[m*n / 2];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int p = abs(vv[i][j] - mean);
                debug(p, vv[i][j])
                    if(p % k == 0)
                        ans += p / k;
                    else
                    {
                        cout << -1;
                        return;
                    }
                debug(ans);
            }
        }
        ans1 = min(ans1, ans);
        debug(mean)
    } else
    {
        ans = 0;
        int mean = v[m*n / 2];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int p = abs(vv[i][j] - mean);
                debug(p, vv[i][j])
                    if(p % k == 0)
                        ans += p / k;
                    else
                    {
                        cout << -1;
                        return;
                    }
                debug(ans);
            }
        }
        ans1 = min(ans1, ans);
        debug(mean)
    }
    debug(vv);
    cout << ans1;
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

