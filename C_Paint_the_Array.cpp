// clang-format off
#include "bits/stdc++.h"
using namespace std;
#define nl "\n"
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 998244353; const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve()
{
    int n = 0, a = 0, b = 0, k = 0, ans = 0;
    cin >> n;
    // debug(a, b);
    map<int, int> mp1, mp2;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        int temp1;
        cin >> temp1;
        temp.push_back(temp1);
    }
    int gcd1 = temp[0], gcd2 = temp[1];
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            gcd1 = __gcd(gcd1, temp[i]);
            mp1[temp[i]]++;
            if (mp2[temp[i]])
            {
                cout << 0;
                return;
            }
        }
        else
        {
            gcd2 = __gcd(gcd2, temp[i]);
            mp2[temp[i]]++;
            if (mp1[temp[i]])
            {
                cout << 0;
                return;
            }
        }
    }
    debug(temp, mp1, mp2, gcd1, gcd2);

    {
        {
            for (int i = 1; i < n; i += 2)
            {
                if (temp[i] % gcd1 == 0)
                {
                    gcd1 = 0;
                    break;
                }
            }
            //test
            for (int i = 0; i < n; i += 2)
            {
                if (temp[i] % gcd2 == 0)
                {
                    gcd2 = 0;
                    break;
                }
            }
        }
        if (gcd1 > 0 || gcd2 > 0)
            cout << max(gcd1, gcd2);
        else
            cout << 0;
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
