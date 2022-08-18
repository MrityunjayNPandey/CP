/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 11-07-2022 21:48:30
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
    vector<int> v(n), v1;
    map<int, int> mp, mp1;
    for(int i = 0; i < n; i++)
        cin >> v[i], mp[v[i]]++, sum += v[i];
    int neg = 0, pos = 0, zero = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i] < 0)
            neg++, cnt++, v1.pb(v[i]);
        else if(v[i] > 0)
            pos++, cnt++, v1.pb(v[i]);
        else
            zero++;
    }
    if(((neg >= 2 || pos >= 2) && zero) || (neg >= 3 || pos >= 3) || cnt >= 5)
    {
        cout << "NO";
    } else
    {
        if(zero)
            v1.pb(0);
        for(int i = 0; i < v1.size(); i++)
            for(int j = i + 1; j < v1.size(); j++)
                for(int k = j + 1; k < v1.size(); k++)
                {
                    if(!mp[v1[i] + v1[j] + v1[k]])
                    {
                        cout << "NO";
                        return;
                    }
                }
        cout << "YES";
    }
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

