/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 31-03-2022 21:31:54
**/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define dclear(x)
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long

int n, dp[MAX_N], prefix[MAX_N];
void solve()
{
    // int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    string str, str1;
    cin >> str;
    // for(int i = 0; i < str.length() - 1; i++)
    // {
    //     if(str[i] == str[i + 1])
    //     {
    //         k++;
    //     } else
    //     {
    //         if((k + 1) % 2 != 0 || k == 0)
    //             str1 += str[i];
    //         k = 0;
    //     }
    // }
    // if((k + 1) % 2 != 0)
    //     str1 += str[str.length() - 1];
    // debug(str1)
    n = str.size();
    str1 = " ";
    str = str1 + str;
    set<int> v[100];
    for(int i = 1; i < n + 1; i++)
    {
        v[str[i] - 'a'].insert(i);
        dp[i] = prefix[i] = 0;
    }
    for(int i = 1; i < n + 1; i++)
    {
        prefix[i] = max(dp[i], prefix[i - 1]);
        auto it = v[str[i] - 'a'].upper_bound(i);
        if(it != v[str[i] - 'a'].end())
        {
            int temp = *it;
            dp[temp] = max(dp[temp], prefix[i - 1] + 1);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << n - (ans * 2);
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

