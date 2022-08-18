/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 11-06-2022 12:37:16
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
#define LOG(n) 31 - __builtin_clz(n)
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
#define int long long

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0, x, y;
    cin >> x >> y;
    int r = x, s = y;
    if(!x || !y)
    {
        if(x == y)
            cout << 0;
        else
            cout << -1;
        return;
    }
    int p = max(x, y) - min(x, y);
    while(x != 0 && y != 0)
    {
        int t = 2, t1 = 3;
        while(p / t1 > min(x, y))
        {
            k++;
            t <<= 1;
            t1 += t;
            debug(t1)
        }
        if(x < y)
        {
            int x1 = x - p / t1;
            x = p / t1;
            y -= x1;
            ans += x1;
        } else
        {
            int x1 = y - p / t1;
            y = p / t1;
            x -= x1;
            ans += x1;
        }
        if(x < y)
        {
            while(x < y) x *= 2, ans++;
            if(x - y >= y - x / 2)
                x /= 2, ans--;
            debug(x, y, ans)
        } else
        {
            while(y < x) y *= 2, ans++;
            if(y - x >= x - y / 2)
                y /= 2, ans--;
            debug(x, y, ans);
        }
            if(x == y)
            {
                ans += x;
                x = y = 0;
                debug(x, y, ans);
                break;
            } else
            {
                int p = x, q = y;
                x -= min(p, q) - 1;
                y -= min(p, q) - 1;
                ans += min(p, q) - 1;
                debug(x, y, ans)
            }
            debug(x, y, ans);
    }
    cout << ans;
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

