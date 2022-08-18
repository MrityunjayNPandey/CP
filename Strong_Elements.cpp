/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 25-06-2022 17:05:13
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
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int p, index = 0;
    int ansf = 1;
    for(int i = 0; i < n - 1; i++)
    {
        if(i == 0)
        {
            p = v[i];
            ans = __gcd(v[i], v[i + 1]);
        } else
        {
            p = ans;
            ans = __gcd(ans, v[i + 1]);
        }
        if(ans == 1)
        {
            if(k)
            {
                k++;
                ansf = 0;
                break;
            }
            ans = p;
            k++;
            index = i + 1;
        }
    }
    debug(k, index, ans);
    if(ans > 1 && !k)
    {
        cout << n;
        return;
    }
    k = 0;
    int d = 0;
    for(int i = n - 1; i > 0; i--)
    {
        if(i == n - 1)
        {
            p = v[i];
            ans = __gcd(v[i], v[i - 1]);
        } else
        {
            p = ans;
            ans = __gcd(ans, v[i - 1]);
        }
        if(ans == 1)
        {
            if(k)
            {
                k++;
                break;
            }
            ans = p;
            debug(index, i-1)
            if(index != i - 1 && ansf)
                d++;
            k++;
        }
    }
    if(k == 1 && d)
    {
        ansf = 2;
    } else if(k == 1)
        ansf = 1;
    cout << ansf;
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

