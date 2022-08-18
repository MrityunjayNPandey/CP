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
    int n = 0, k = 0, l = 0, r = 0, ans = 0;
    vector<int> v, vo, ve;
    vector<pair<int, int>> vp;
    unordered_map<int, int> mp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.pb(x);
        if (x % 2 == 0)
            ve.pb(i);
        else
            vo.pb(i);
    }
    debug(ve, vo);
    for (int i = 0; i < n - 1; i += 2)
    {

        if ((v[i] % 2 == 0 && v[i + 1] % 2 == 0) || (v[i] % 2 == 1 && v[i + 1] % 2 == 1))
        {
            if (v[i] % 2 == 0)
            {
                if (vo.size() == 0)
                {
                    cout << -1 << endl;
                    return;
                }
                ans++;
                vp.pb({i, vo[0]});
                for (auto it = ve.begin(); it != ve.end(); ++it)
                {
                    if (*it == i)
                    {
                        ve.erase(it);
                        break;
                    }
                }
                vo.pb(i);
            }
            else
            {
                for (auto it = vo.begin(); it != vo.end(); ++it)
                {
                    if (*it == i)
                    {
                        vo.erase(it);
                        break;
                    }
                }
                if (vo.size() == 0)
                {
                    cout << -1 << endl;
                    return;
                }
                ans++;
                vp.pb({i, vo[0]});
                ve.pb(i);
            }
        }
    }
    int i = n - 2;
    if ((v[i] % 2 == 0 && v[i + 1] % 2 == 0) || (v[i] % 2 == 1 && v[i + 1] % 2 == 1))
    {
        if (v[i + 1] % 2 == 0)
        {
            if (vo.size() == 0)
            {
                cout << -1 << endl;
                return;
            }
            ans++;
            vp.pb({i + 1, vo[0]});
            for (auto it = ve.begin(); it != ve.end(); ++it)
            {
                if (*it == i + 1)
                {
                    ve.erase(it);
                    break;
                }
            }
            vo.pb(i + 1);
        }
        else
        {
            for (auto it = vo.begin(); it != vo.end(); ++it)
            {
                if (*it == i + 1)
                {
                    vo.erase(it);
                    break;
                }
            }
            if (vo.size() == 0)
            {
                cout << -1 << endl;
                return;
            }
            ans++;
            vp.pb({i + 1, vo[0]});
            ve.pb(i + 1);
        }
    }
    cout << ans << endl;
    for (int i = 0; i < vp.size(); i++)
    {
        cout << vp[i].first + 1 << " " << vp[i].second + 1 << endl;
    }
}

// clang-format off
int32_t main()
{
    ios;
    #ifdef LOCAL
    free
    #endif
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef DEBUG
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}