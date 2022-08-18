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

void solve()
{
    int n = 0, k = 0, ans = 0, d = 0, v[2000];
    cin >> n >> k >> d;
    v[n - 1] = n - 1;
    for(int i = 0;i < d;i++)
        v[n - 1] /= k;
    if(v[n - 1])
    {
        cout << -1; return;
    }
    for(int i = 0;i < n;i++)
        v[i] = i;
    for(int i = 0;i < d;i++)
    {
        for(int j = 0;j < n;j++)
            cout << v[j] % k + 1 << ' ', v[j] /= k;
        cout << '\n';
    }
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

