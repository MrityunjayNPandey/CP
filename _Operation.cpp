// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 
#endif
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e18;
const long long MOD = 1e9+7; const long long mod = 998244353;
#define int long long
int I;
// clang-format on

// Sieve of Eratosthenes, time complexity of O(N*log(logN))
unordered_map<int, int> mprime;
vector<int> primetemp(MAX_N, 1), prime;
void SIEVE()
{
    for (int p = 2; p <= MAX_N; p++)
    {
        if (primetemp[p] == 1)
        {
            for (int i = p * p; i <= MAX_N; i += p)
            {
                primetemp[i] = 0;
            }
        }
    }
    prime.pb(1);
    for (int i = 2; i <= MAX_N; i++)
    {
        if (primetemp[i] == 1)
        {
            prime.pb(i);
            mprime[i]++;
        }
    }
}

void solve()
{
    int n = 0, k = 0, ans = 0;
}

// clang-format off
int32_t main()
{
    ios;
    int Test = 1;
    SIEVE();
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef LOCAL
        cerr << "-------" << I << "-------" << nl;
        #endif
        solve();
        cout << endl;
    }
}
