#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
int I;

int n, m, k;
char ch[501][501];
int vis[501][501];
void dfs(int x, int y)
{
    if(x<1 || x>n || y<1 || y>m || ch[x][y] != '.' || vis[x][y]) return;
    vis[x][y] = 1;
    dfs(x + 1, y);dfs(x - 1, y);
    dfs(x, y + 1);dfs(x, y - 1);
    if(k) ch[x][y] = 'X', k--;
}

void solve()
{
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)
        cin >> ch[i] + 1;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            if(ch[i][j] == '.' && k) dfs(i, j);
    for(int i = 1;i <= n;i++) cout << ch[i] + 1 << endl;
}

int32_t main()
{
    ios;
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    // cin >> Test;
    for(I = 1; I <= Test; I++)
    {
        cerr << "-------" << I << "-------" << endl;
        solve();
        cout << endl;
    }
}

