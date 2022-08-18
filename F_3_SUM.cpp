/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 16-06-2022 11:33:12
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
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    map<tuple<int, int, int>, int> mp;
    int target = 3;
    int x = 3, y = 0, z = 0;
    mp[{1, 1, 1}]++;
    while(x >= 1)
    {
        if(y + z && y > 1 && z > 1)
        {
            y--;
            z++;
        }
        mp[{x, y, z}]++;
        x--; y++;
    }
    debug(mp);
    int z1 = 4;
    x = 9, y = 4, z = 0;
    while(x >= 1)
    {
        if(y + z && y > 1 && z < 13 - x)
        {
            y--;
            z++;
        } else
        {
            x--; y = 13 - x;z = 0;
        }
        if(x + y + z == 13 && x < 10 && y < 10 && z < 10)
            mp[{x, y, z}]++;
    }
    mp[{9, 9, 5}]++;
    mp[{9, 8, 6}]++;
    mp[{9, 7, 7}]++;
    mp[{8, 8, 7}]++;
    mp[{8, 7, 8}]++;
    mp[{8, 6, 9}]++;
    debug(mp);
    map<int, int> mp1;
    for(int i = 0; i < n; i++)
        mp1[v[i] % 10]++;
    for(auto i : mp)
    {
        map<int, int> mp2 = mp1;
        int ans = 0;
        if(mp2[get<0>(i.first)] > 0)
            mp2[get<0>(i.first)]--, ans++;
        if(mp2[get<1>(i.first)] > 0)
            mp2[get<1>(i.first)]--, ans++;
        if(mp2[get<2>(i.first)] > 0)
            mp2[get<2>(i.first)]--, ans++;
        if(ans >= 3)
        {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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

