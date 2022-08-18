/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 17-02-2022 10:43:35
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
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
int I;

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0, a[1000001], p=0;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        a[i] = a[i - 1] ^ i;
        cin >> p;
        ans ^= p ^ a[n % i] ^ (((n / i) % 2) * a[i - 1]);
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
    for(I = 1; I <= Test; I++)
    {
#ifdef DEBUG
        cerr << "-------" << I << "-------" << endl;dclear();
#endif
        solve();
        cout << endl;
    }
}

