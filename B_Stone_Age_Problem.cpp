/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 14-05-2022 15:22:41
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
    int a[200005], t[200005];
    int q, op, b, tim;
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0, x;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i], sum += a[i], t[i] = 1;
    for(int i = 1;i <= q;i++)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> k >> x;int aa;
            if(t[k] > tim) aa = a[k];
            else aa = b;
            a[k] = x, t[k] = i;
            sum += (x - aa);
        } else
        {
            cin >> x;
            tim = i, b = x;
            sum = n * x;
        }cout << sum << endl;
    }
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