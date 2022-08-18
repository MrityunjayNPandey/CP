// clang-format off
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
const long long MOD = 1e9+7; const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve()
{
    int k, x;
    cin >> k >> x;
    int l = 1, r = k, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int p = (mid * (mid + 1)) / 2;
        if (p <= x)
        {
            ans = max(ans, mid);
            if (l == r)
                break;
            l = mid + 1;
        }
        else
        {
            if (l == r)
                break;
            r = mid;
        }
    }
    int q = (ans * (ans + 1)) / 2;
    if (q < x)
    {
        ans = min(ans + 1, k);
    }
    q = (ans * (ans + 1)) / 2;
    if (q >= x)
    {
        cout << ans << endl;
        return;
    }
    x -= q;
    l = 1, r = k - 1;
    int _ans = k;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int p = (k - mid) * (2 * mid + (k - mid - 1)) / 2;
        if (p <= x)
        {
            _ans = min(_ans, mid);
            if (l == r)
                break;
            r = mid;
        }
        else
        {
            if (l == r)
                break;
            l = mid + 1;
        }
    }
    q = (k - _ans) * (2 * (_ans) + (k - _ans - 1)) / 2;
    if (q < x)
    {
        _ans = max(1LL, _ans - 1);
    }
    cout << ans + (k - _ans) << endl;
}

// clang-format off
int32_t main()
{
    ios;
    // #ifdef SUBLIME
    // free
    // #endif
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef DEBUG
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        // cout << endl;
    }
}

