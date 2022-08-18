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
    cin >> n;
    unordered_map<int, int> mp, mp2;
    vector<int> v, v1;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        mp[temp]++;
        if (temp > n || mp[temp] > 1)
        {
            v1.pb(temp);
            mp[temp]--;
        }
        else
            v.pb(temp);
    }
    sort(all(v));
    sort(all(v1));
    debug(v1);
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == 0)
        {
            if (v1[t] % (v1[t] - i) == i)
                ans++;
            else
            {
                cout << -1;
                return;
            }
            t++;
        }
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
