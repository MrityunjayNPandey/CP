
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
    int n, m, k, i, ans = 0;
    int c, s, t, p = 0, q = 0;
    cin >> n;
    vector<int>a(n);
    for(auto& it : a)
        cin >> it, p += it;
    cin >> m;
    vector<int>v1(m);
    for(auto& it : v1)
        cin >> it, q += it;
    cin >> k;
    k = n + m - k;
    for(int l = 0;l <= k;l++)
    {
        if(k - l > m || l > n)
            continue;
        for(i = 0, c = 0;i < l;i++)c += a[i];
        s = c;
        for(;i < n;i++)c += a[i] - a[i - l], s = min(s, c);
        for(i = 0, c = 0;i < k - l;i++)c += v1[i];
        t = c;
        for(;i < m;i++)c += v1[i] - v1[i - k + l], t = min(t, c);
        ans = max(ans, p - s + q - t);
    }cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    // pref();
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        cout << "Case #" << I << ": ";
        dclear(I);
        solve();
        cout << endl;
    }
}

