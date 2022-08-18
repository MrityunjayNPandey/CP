/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 15-06-2022 19:33:00
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define print(x)
#define dclear(x)
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
#define int long long

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m >> k;
    vector<vector<char>> vv(n + 2, vector<char>(m + 2, '.'));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> vv[i][j];
    vector<pair<int, int>> center;
    map<pair<int, int>, int> mp;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(vv[i][j] == '*')
            {
                mp[{i, j}]++;
                ans++;
                if(vv[i - 1][j - 1] == vv[i - 1][j + 1] && vv[i - 1][j - 1] == '*')
                {
                    center.pb({ i, j });
                    mp.erase({ i, j });
                }
            }
        }
    debug(center);
    sum = 0;
    for(int i = center.size() - 1; i >= 0; i--)
    {
        int t = 1, cnt = 0;
        sum = 0;
        debug(center[i].first - t, center[i].second - t, center[i].second + t)
            while(center[i].first - t >= 0 && center[i].second - t >= 0 && center[i].second + t <= m + 1)
            {
                if(vv[center[i].first - t][center[i].second - t] == vv[center[i].first - t][center[i].second + t] && vv[center[i].first - t][center[i].second + t] == '*')
                {
                    debug(cnt)
                        cnt++;
                    if(cnt >= k)
                    {
                        sum++;
                        break;
                    }
                    t++;
                } else
                    break;
            }
        debug(sum);
        t = 0;
        if(sum)
            while(center[i].first - t >= 0 && center[i].second - t >= 0 && center[i].second + t <= m + 1)
            {
                if(vv[center[i].first - t][center[i].second - t] == vv[center[i].first - t][center[i].second + t] && vv[center[i].first - t][center[i].second + t] == '*')
                {
                    mp[{center[i].first - t, center[i].second - t}]--;
                    mp[{center[i].first - t, center[i].second + t}]--;
                    t++;
                } else
                    break;
            }
    }
    debug(mp, mp.size())
        for(auto i : mp)
        {
            if(i.second > 0)
            {
                cout << "NO";
                return;
            }
        }
    cout << "YES";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

