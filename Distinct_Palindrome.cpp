/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 15-06-2022 20:15:55
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
    cin >> n >> m;
    if(m > n / 2 && m != 1 && (n / 2 + 1 != m))
    {
        cout << -1;
    } else
    {
        if(n % 2 == 0 && m > n / 2)
        {
            cout << -1;
            return;
        }
        char p = 'a';
        string str, astr;
        int k = 0;
        for(int i = 0; i < n / 2; i++)
        {
            str += p;
            p++, k++;
            if(k == m)
                p = 'a', k = 0;
        }
        if(k == m)
            p = 'a';
        astr += str;
        if(n % 2 != 0)
            astr += p;
        reverse(str.begin(), str.end());
        astr += str;
        cout << astr;
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
