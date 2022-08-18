/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 15-02-2022 19:18:54
**/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define dclear()
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
// const int_fast32_t INF = 1ll << 32; const int_fast32_t MAX_N = 1e6 + 7;
const int_fast32_t MOD = 1e9 + 7; const int_fast32_t mod = 998244353;
#define int int_fast32_t
int I;
const int N = 2e3 + 123;
const int INF = 1e9 + 1;
void solve()
{
    int n, m, x, y;
    pair < int, int > pref[N];
    pair < int, int > dp[N];
    int a[N], b[N];
    cin >> n >> m >> x >> y;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            char x; cin >> x;
            a[j] += (x == '#');
            b[j] += (x == '.');
        }
    }
    for(int i = 1;i <= m;i++)
    {
        pref[i] = make_pair(pref[i - 1].first + a[i], pref[i - 1].second + b[i]);
        dp[i] = make_pair(INF, INF);
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = x;j <= y;j++)
        {
            if(i - j < 0)	break;
            dp[i].first = min(dp[i].first, dp[i - j].second + pref[i].first - pref[i - j].first);
            dp[i].second = min(dp[i].second, dp[i - j].first + pref[i].second - pref[i - j].second);
        }
    }
    cout << min(dp[m].first, dp[m].second);
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
        clog << "-------" << I << "-------" << endl;dclear();
#endif
        solve();
        cout << endl;
    }
}

