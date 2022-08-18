/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 20-07-2022 22:18:27
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
    int n;
    string str;
    cin >> n >> str;
    string str1 = str;
    reverse(all(str));
    vector<vector<int>> dp2d(n + 1, vector<int>(n + 1, 0));
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(str1[i - 1] != str[j - 1])
                dp2d[i][j] = max(dp2d[i][j - 1], dp2d[i - 1][j]);
            else
                dp2d[i][j] = dp2d[i - 1][j - 1] + 1;
        }
    }
    int st = n, end = n;
    string res = "";
    while(st > 0 && end > 0)
    {
        if(str1[st - 1] == str[end - 1])
        {
            res = str1[st - 1] + res;
            st--, end--;
        } else if(dp2d[st - 1][end] > dp2d[st][end - 1])
        {
            st = st - 1;
        } else
        {
            end = end - 1;
        }
    }
    cout << res;
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