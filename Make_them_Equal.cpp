/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 15-06-2022 21:03:15
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

map<int, int> mp1, mp2;

void pref()
{
    int x = 1, x1 = 0;
    mp1[0]++, mp2[0]++, mp2[1]++;
    while(x < 1e10)
    {
        x <<= 1;
        x1 += x;
        mp1[x1]++;
        mp2[x1 + 1]++;
    }
    // debug(mp1, mp2)
}

unsigned int count_1bits(unsigned int x)
{
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x0000003F;
}

unsigned int count_0bits(unsigned int x)
{
    return 32 - count_1bits(x);
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    vector<int> v(3);
    for(int i = 0; i < 3; i++)
    {
        cin >> v[i];
    }
    sort(all(v));
    int p = v[2] - v[0];
    int q = v[2] - v[1];
    debug(p, q);
    if((p & 1 && q & 1))
    {
        if(p & 1 && q & 1)
        {
            p++, q++;
        }
        int x = p + q + 1;
        if(LOG(x) + 1 - __builtin_popcountll(x) == 0)
            cout << "YES";
        else
            cout << "NO";
    } else if(!(p & 1) && !(q & 1))
    {
        cout << "NO";
    } else
    {
        int x = p + q;
        if(LOG(x) + 1 - __builtin_popcountll(x) == 0)
        {
            cout << "YES";
        }
        else
            cout << "NO";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        pref();
    int Test = 1;
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

