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
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
const long long INF = 1ll << 32;
const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve()
{
    int n = 0, x = 0, k = 0, ans = 0, p = 0, no1 = 0, no0 = 0;
    cin >> n >> x;
    string str;
    cin >> str;
    vector<pair<int, int>> vp, vp1;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1')
        {
            no1++;
        }
        if (str[i] == '0')
        {
            no0++;
        }
        if (str[i] == '0' && k == 0)
        {
            k++;
            p = i;
        }
        if (k != 0 && (str[i] == '1' || i + 1 == str.length()))
        {
            k = 0;
            if (str[i] == '1')
            {
                vp.push_back({p, i - 1});
            }
            else
                vp.push_back({p, i});
        }
    }
    if (no1 == 0)
    {
        cout << 0;
        return;
    }
    if (no0 == 0 && x == 1)
    {
        cout << 1;
        return;
    }
    debug(vp);
    map<int, int> mp;
    k = 0;
    for (int i = 1; i < vp.size(); i++)
    {
        if (vp[i - 1].second + 2 == vp[i].first)
        {
            mp[i - 1]++;
            k++;
        }
    }
    debug(mp);
    if (k != 0)
    {
        for (auto i : mp)
        {
            debug(vp);
            int k1 = vp[i.first].first;
            debug(k1) int l = ((vp[i.first].second - vp[i.first].first + 1) + 1 + (vp[i.first + 1].second - vp[i.first + 1].first + 1)) / x;
            int m = (vp[i.first].second - vp[i.first].first + 1) / x;
            int m1 = (vp[i.first + 1].second - vp[i.first + 1].first + 1) / x;
            debug(l, m, m1);
            if (l > m + m1)
            {
                vp[i.first + 1].first = k1;
                vp.erase(vp.begin() + i.first);
                debug(vp) for (int j = 0; j < vp.size(); j++)
                {
                    int l1 = vp[j].second - vp[j].first + 1;
                    debug(l1)
                        ans += (l1 / x);
                }
                cout << ans;
                return;
            }
        }

        int k1b = 0;
        for (int i = 0; i < vp.size(); i++)
        {
            int l1 = vp[i].second - vp[i].first + 1;
            if ((l1 + 1) / x != (l1 / x) && (str[vp[i].second + 1] == '1' || str[vp[i].first - 1] == '1') && k1b == 0)
            {
                l1++;
                k1b++;
            }
            ans += (l1 / x);
        }
        cout << ans;
        return;
    }
    else
    {
        debug(vp);
        int k1b = 0;
        for (int i = 0; i < vp.size(); i++)
        {
            int l1 = vp[i].second - vp[i].first + 1;
            if ((l1 + 1) / x != (l1 / x) && (str[vp[i].second + 1] == '1' || str[vp[i].first - 1] == '1') && k1b == 0)
            {
                l1++;
                k1b++;
            }
            ans += (l1 / x);
        }
        cout << ans;
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
