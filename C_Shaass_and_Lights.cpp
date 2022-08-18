/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 03-04-2022 02:09:38
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
    int n = 0, m = 0, k = 0, ans = 1, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<int> v;
    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        v.pb(temp);
    }
    sort(all(v));
    int nCr[1001][1001];

    /*
    NOTE: n!/p!q!r! = pCp * q+pCq * p+q+rCr
    use this formula to get the answer correctly.
    */
    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= i;j++)
        {
            if(j == 0 || j == i) nCr[i][j] = 1;
            else nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
        }
    }
    ans = (ans * nCr[v[0] - 1][v[0] - 1]) % MOD;
    cnt += v[0] - 1;
    debug(ans);
    for(int i = 1; i < m; i++)
    {
        cnt += v[i] - v[i - 1] - 1;
        ans = (ans * nCr[cnt][v[i] - v[i - 1] - 1]) % MOD;
        for(int j = 0; j < v[i] - v[i - 1] - 2;j++)
        {
            ans *= 2;
            ans %= MOD;
        }
        debug(cnt, nCr[cnt][v[i] - v[i - 1] - 1], ans);
        debug(ans);
    }
    cnt += n - v[m - 1];
    ans = (ans * nCr[cnt][n - v[m - 1]]) % MOD;
    cout << ans;
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

