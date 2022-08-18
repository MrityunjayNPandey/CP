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
    vector<vector<int>> adj_list;
    vector<pair<int, int>> v;
    vector<int> v1;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.pb({temp, i});
        mp[temp]++;
    }
    debug(v, mp);
    if (mp[v[0].first] == n)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int t = 0;
    v1.pb(v[0].second);
    for (int i = 0; i < n; i++)
    {
        if (v[i].first == v[0].first)
            continue;
        t = v[i].second;
        v1.pb(v[i].second);
    }
    adj_list.pb(v1);
    v1.clear();
    debug(adj_list);
    debug(t);
    debug(v[0].first);
    if (mp[v[0].first] > 1)
    {
        v1.pb(t);
        for (int i = 1; i < n; i++)
        {
            if (v[i].first == v[0].first)
                v1.pb(v[i].second);
        }
        adj_list.pb(v1);
    }
    debug(adj_list) for (int i = 1; i < adj_list[0].size(); i++)
    {
        cout << adj_list[0][0] + 1 << " " << adj_list[0][i] + 1 << endl;
    }
    if (mp[v[0].first] > 1)
    {
        for (int i = 1; i < adj_list[1].size(); i++)
        {
            cout << adj_list[1][0] + 1 << " " << adj_list[1][i] + 1 << endl;
        }
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
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        // cout << endl;
    }
}
