// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef joKer
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

                    // do something, stay focused
                    // look for stupid bugs
                    // guess, slow, stress
                    // don't overgeneralize
                    // don't rush
                        
                    // 1. Understand the problem
                    // 2. Devise a plan
                    // 3. Carry out the plan
                    // 4. Look back
                        
                    // don't waste time on standings
                        
                    // SOLVE THE PROBLEM OR DIE TRYING
                    // THE SOLUTION IS ALWAYS SIMPLE
                    // THE CODE IS ALWAYS SHORT

// clang-format on

void solve()
{
    int n = 0, k = 0, ans = 0;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < 2 * n; i++)
    {
        int temp;
        cin >> temp;
        if (i < n)
        {
            v.pb({temp, 0});
        }
        else
        {
            v[i - n].second = temp;
        }
    }
    sort(all(v));
    debug(v);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 1; j <= v[i].first; j++)
        {
            {
                debug(v[i].first, k);
                if (v[i].first == 1)
                {
                    ans += v[i].second;
                    break;
                }
                if (v[i].first <= pow(2, j) && k > 0)
                {
                    ans += v[i].second;
                    k--;
                    break;
                }
                else
                    k--;
                debug(v[i].first, k, ans);
                if (k <= 0)
                    break;
            }
        }
        debug(k, ans)
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
        #ifdef joKer
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}
