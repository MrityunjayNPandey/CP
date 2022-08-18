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
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 998244353; const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve()
{
    int n = 0, k = 0, ans = 0, p = 0;
    string str;
    cin >> str;
    for (int i = 0; i < str.length() - 1; i++)
    {
        int p1 = ((int)str[i] - '0'), p2 = ((int)str[i + 1] - '0');

        if ((p1 + p2) / 10 >= 1)
        {
            debug(p1, p2);
            p = i;
            k++;
        }
    }
    if (k != 0)
    {
        int p1 = ((int)str[p] - '0'), p2 = ((int)str[p + 1] - '0');
        str[p] = (char)((p1 + p2) / 10) + '0';
        str[p + 1] = (char)((p1 + p2) % 10) + '0';
        cout << str;
        debug((char)((p1 + p2) / 10) + '0', (char)((p1 + p2) % 10) + '0');
        return;
    }
    for (int i = 0; i < str.length() - 1; i++)
    {
        int k;
        int p1 = ((int)str[i] - '0'), p2 = ((int)str[i + 1] - '0');
        debug(p1, p2);
        debug((char)((p1 + p2) / 10) + '0', (char)((p1 + p2) % 10) + '0');
        str[i] = (char)((p1 + p2) / 10) + '0';
        str[i + 1] = (char)((p1 + p2) % 10) + '0';
        str.erase(str.begin() + i);
        cout << str;
        return;
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
        cerr << "-------" << I << "-------" << nl;
        #endif
        solve();
        cout << endl;
    }
}
