/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 10-05-2022 01:24:37
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

void solve()
{
    int n = 0, m = 0, k = 1, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    string str;
    cin >> str;
    vector<int> v;
    for(int i = 1; i < n; i++)
    {
        if(str[i] != str[i - 1])
        {
            v.pb(k);
            k = 0;
        }
        k++;
    }
    v.pb(k);
    vector<int> v1 = v;
    debug(v, v1);
    for(int i = 0; i < v1.size() - 1; i++)
    {
        if(v1[i] & 1)
        {
            v1[i]++;
            v1[i + 1]--;
            cnt++;
        }
    }
    cout << cnt << " ";
    int t = -1;
    for(int i = 0; i < n; i += 2)
    {
        if(str[i] == str[i + 1])
        {
            if(t != str[i])
            {
                t = str[i];
                ans++;
            }
        }
    }
    cout << max(ans, 1LL);
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

