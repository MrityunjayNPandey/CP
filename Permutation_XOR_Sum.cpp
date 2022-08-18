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
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9+7; const long long mod = 998244353;
#define int long long
int I;
// clang-format on

int flip(int n)
{
    int num = 0, cnt = 0;
    while (n)
    {
        if (n % 2 == 0)
            num += (1LL << cnt);
        n /= 2, cnt++;
        if (n <= 0)
            break;
    }
    return num;
}

void solve()
{
    int n = 0, k = 0, ans = 0;
    cin >> n;
    while (n > 0)
    {
        int a = flip(n);
        int b = n;
        if ((b & (b + 1)) == 0)
            b--;
        int val = ((b * (b + 1)) / 2) - ((a * (a - 1)) / 2);
        ans += (val * 2);
        n = a - 1;
    }
    cout << ans;
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
