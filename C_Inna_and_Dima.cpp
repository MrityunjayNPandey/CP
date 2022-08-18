/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 16-04-2022 17:38:06
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

const int N = 2022;
int n, m, ans, flag, f[N][N], dp[N][N];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
char a[N][N], t[] = " DIMA";
int dfs(int x, int y, int s)
{
    if(a[x][y] != t[(s - 1) % 4 + 1])return 0;
    if(f[x][y])flag = 1;
    if(dp[x][y])return dp[x][y];
    dp[x][y] = 1, f[x][y] = 1;
    for(int i = 0;i < 4;i++)
        dp[x][y] = max(dfs(x + dx[i], y + dy[i], s + 1) + 1, dp[x][y]);
    f[x][y] = 0;
    return dp[x][y];
}


void solve()
{
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++)scanf("%s", a[i] + 1);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            if(a[i][j] == 'D')ans = max(dfs(i, j, 1) / 4, ans);
    if(flag)printf("Poor Inna!");
    else if(ans == 0)printf("Poor Dima!");
    else printf("%d", ans);
    return;
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

