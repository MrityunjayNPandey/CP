/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 19-05-2022 21:01:22
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
    int n, m, t = 0, p = -1, s = -1;
    cin >> n >> m;
    vector<vector<int>> vv(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> vv[i][j];
    }
    for(int i = 0;i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(vv[i][j] < vv[i][j - 1])
            {
                vector<int> v = vv[i];
                sort(all(v));
                for(int j = 0; j < m; j++)
                {
                    if(vv[i][j] != v[j])
                    {
                        if(p == -1)
                            p = j;
                        else if(s == -1)
                            s = j;
                        else
                        {
                            cout << -1;
                            return;
                        }
                    }
                }
                t = 1;
            }
            if(t != 0) break;
        }
        if(t != 0) break;
    }
    if(t == 0)
    {
        cout << 1 << " " << 1;
        return;
    }
    if(p == -1 || s == -1)
    {
        cout << -1;
        return;
    }
    int k;
    for(int i = 0; i < n; i++)
    {
        k = vv[i][p];
        vv[i][p] = vv[i][s];
        vv[i][s] = k;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(vv[i][j] < vv[i][j - 1])
            {
                cout << -1;
                return;
            }
        }
    }
    p++, s++;
    cout << p << " " << s;
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

