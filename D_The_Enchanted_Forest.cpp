/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 06-06-2022 16:31:07
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
    int n = 0, m = 0, k = 0, ans = INT_MIN, cnt = 0, sum = 0;
    cin >> n >> k;
    vector<int> v(n + 1);
    for(int i = 1;i <= n;i++)cin >> v[i];
    vector<int> sumv(n + 1);
    sumv[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        sumv[i] = sumv[i - 1] + v[i];
    }
    if(k <= n)
    {
        for(int i = 0;i <= n - k;i++)
        {
            ans = max(ans, sumv[i + k] - sumv[i]);
        }
        ans += k * (k - 1) / 2;
    } else ans = sumv[n] + n * (2 * k - n - 1) / 2;
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

