// try testcase
/*
8
ghedaaaa
5
baaab
this should be correct ans: baaaab
*/

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
    int n = 0, k = 0;
    cin >> n;
    string str, ans;
    char a;
    cin >> str;
    if (str[0] == str[1])
    {
        cout << str[0] << str[0];
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        ans += str[i];
        if (str[i] < str[i + 1])
        {
            // int p = ans.length();
            // char l = ans[p - 1];
            // float k1 = 0;
            // for (int j = p; j > 0; j--)
            // {
            //     if (ans[j] == l && ans[j] == ans[j - 1])
            //     {
            //         k1++;
            //         ans.pop_back();
            //     }
            // }
            // debug(p, ans)
            //     k1 /= 2;
            // debug(k1, ceil(k1)) for (int j = 0; j < ceil(k1); j++)
            // {
            //     ans += l;
            // }
            debug(ans);
            cout
                << ans;
            for (int j = ans.length() - 1; j >= 0; j--)
            {
                cout << ans[j];
                debug(ans[j])
            }
            return;
        }
    }
    if (str[1] < str[0])
    {
        cout << str;
        for (int j = str.length() - 1; j >= 0; j--)
        {
            cout << str[j];
            debug(ans[j])
        }
    }
    else
        cout << str[0] << str[0];
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
