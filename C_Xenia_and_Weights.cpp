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
int n;
string st;
int m, a[1005];
bool dfs(int p, int s)
{
    if(p > m) return true;

    for(int i = s + 1; i <= 10; i++) if(i != a[p - 1] && st[i - 1] - '0')
    {
        a[p] = i;
        if(dfs(p + 1, i - s)) return true;
    }

    return false;
}

void solve()
{
    cin >> st; cin >> m;
    a[0] = 0;
    if(dfs(1, 0))
    {
        cout << "YES\n";
        for(int i = 1; i <= m; i++) cout << a[i] << " ";
    } else
    {
        cout << "NO";
    }
    return;

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
#ifdef DEBUG
        cerr << "-------" << I << "-------" << endl;
#endif
        solve();
        cout << endl;
    }
}

