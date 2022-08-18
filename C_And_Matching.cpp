// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9+7; const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve()
{
    int n = 0, k = 0, ans = 0;
    cin >> n >> k;
    if (k == 0)
    {
        for (int i = 0; i < n / 2; ++i)
        {
            cout << i << ' ' << n - i - 1 << endl;
        }
        return;
    }
    if (k != n - 1)
    {
        cout << 0 << ' ' << n - k - 1 << endl;
        cout << k << ' ' << n - 1 << endl;
        for (int i = 1; i < n / 2; ++i)
        {
            if (i != k && i != n - k - 1)
            {
                cout << i << ' ' << n - i - 1 << endl;
            }
        }
        return;
    }
    if (n == 4)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << n - 2 << ' ' << n - 1 << endl;
        cout << 1 << ' ' << 3 << endl;
        cout << 0 << ' ' << n - 4 << endl;
        cout << 2 << ' ' << n - 3 << endl;
        for (int i = 4; i < n / 2; ++i)
        {
            cout << i << ' ' << n - i - 1 << endl;
        }
    }
}

// clang-format off
int32_t main()
{
    ios;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef LOCAL
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        // cout << endl;
    }
}
