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
    int n = 0, k = 0, ans = 0, k1 = 0;
    cin >> n >> k;
    string str;
    cin >> str;
    k = k - 1;
    if (k > (n - 1) / 2)
        k = n - k - 1;
    if (n % 2 == 1)
        k++;
    debug(k);
    for (int i = k; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
        {
            ans += min(26 - abs(str[i] - str[n - i - 1]), abs(str[i] - str[n - i - 1]));
            k1 = i;
        }
        debug(ans, str[i], str[n - i - 1])
    }
    int t = 0;
    if (k1 != 0)
        ans += 2 * (k1 - k);
    k1 = 0;
    for (int i = k - 1; i >= 0; i--)
    {
        if (str[i] != str[n - i - 1])
        {
            debug(ans, i, str[i], str[n - i - 1], k1);
            ans += min(26 - abs(str[i] - str[n - i - 1]), abs(str[i] - str[n - i - 1]));
            k1 = i;
            t = 1;
            debug(ans, i, str[i], str[n - i - 1], k1);
        }
    }
    if(t!=0)
    ans += k - k1 - 1 + t;
    else
    ans--;
    cout << ans;
}

// clang-format off
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
        #ifdef DEBUG
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}

