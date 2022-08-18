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
    {
        int a, s, x, y;
        int b = 0, p = 1;
        cin >> a >> s;
        while (a > 0)
        {
            x = a % 10;
            y = s % 10;
            if (y < x)
            {
                s /= 10;
                y += s % 10 * 10;
            }
            if (x > y or (y - x) > 9)
            {
                b = -1;
                break;
            }
            b += p * (y - x);
            a /= 10, s /= 10, p *= 10;
        }
        if (b != -1)
            b += p * s;
        cout << b ;
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
        cout << endl;
    }
}
