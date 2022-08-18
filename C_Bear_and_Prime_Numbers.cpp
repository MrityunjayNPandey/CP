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
const long long INF = 1ll << 32; const long long MAX_N = 10000000;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
int I;

//Sieve of Eratosthenes, time complexity of O(N*log(logN))
int primetemp[MAX_N + 5] = { 1 }, prime[MAX_N], mp[MAX_N + 5], f[MAX_N + 5];
int primenum = 1;
void SIEVE()
{
    for (int p = 2; p <= MAX_N; p++)
    {
        if (primetemp[p] == 1)
        {
            prime[primenum++] = p;
            for (int i = p; i <= MAX_N; i += p)
            {
                primetemp[i] = 0;
            }
        }
    }
}



void solve()
{
    SIEVE();
    int n = 0, m = 0, k = 0, ans = 0;
    cin >> n;
    int maxa = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
        maxa = max(maxa, x);
    }
    // debug(v);
    cin >> m;
    for (int i = 1; i < primenum; ++i)
        for (int j = prime[i]; j <= 10000000; j += prime[i])
            f[i] += mp[j];
    for (int i = 1; i < primenum; ++i)
        f[i] += f[i - 1];
    // debug(f);
    for (int i = 0; i < m; i++)
    {
        int x = 0;
        int y = 0;
        cin >> x >> y;
        ans = 0;
        auto p = lower_bound(prime + 1, prime + primenum, x + 1) - prime - 1;
        auto q = lower_bound(prime + 1, prime + primenum, y + 1) - prime - 1;
        debug(ans, x, maxa, p, q);
        cout << f[q] - f[p] << endl;
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
    for (I = 1; I <= Test; I++)
    {
        // cerr << "-------" << I << "-------" << endl;dclear();
        solve();
        cout << endl;
    }
}

