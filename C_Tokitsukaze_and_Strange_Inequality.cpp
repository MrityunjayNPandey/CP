/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 11-05-2022 20:57:48
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
    // int n = 0, m = 0, k = 0, ans = 0;
    // cin >> n;
    // vector<int> v(n);
    // for(int i = 0; i < n; i++)
    //     cin >> v[i];
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = i + 2; j < n; j++)
    //     {
    //         if(v[j] > v[i])
    //             for(int k = i + 1; k < j; k++)
    //             {
    //                 for(int l = j + 1; l < n; l++)
    //                     if(v[l] < v[k])
    //                         ans++;
    //             }
    //     }
    // }
    // int arr[5];
    // debug(arr)
    // cout << ans;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int p[n + 1][n + 1];
    memset(p, 0, sizeof(p));
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j >= i; j--)
        {
            p[i][j] = p[i][j + 1] + (a[i] > a[j]);
        }
    }
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = n - 1; j > i + 2; j--)
            p[i][j] += p[i + 1][j];
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 2; j < n; j++)
            if(a[i] < a[j])
                ans += p[i + 1][j + 1];
    }
    cout << ans;
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

