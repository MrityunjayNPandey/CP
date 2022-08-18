/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 10-06-2022 14:44:27
**/
#include <bits/stdc++.h>
using namespace std;
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
const long long mod = 998244353; const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7;
#define int long long

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++)
        cin >> v[i], mp[v[i]]++;
    vector<int> v1;
    v1.pb(v[0]);
    for(int i = 1; i < n; i++)
    {
        int t = upper_bound(v1.begin(), v1.end(), v[i]) - v1.begin();
        debug(v1, t);
        if(t == v1.size())
            v1.pb(v[i]);
        else
        {
            ans += v1.size() - t;
            v1.pb(v[i]);
            sort(all(v1));
        }
    }
    for(auto i : mp)
    {
        if(i.second > 1)
        {
            int p = i.second - 1;
            ans += (p * (p + 1)) / 2;
        }
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

