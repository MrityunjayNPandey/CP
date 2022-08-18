/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 26-04-2022 21:09:21
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
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    vector<int> x1(4), x2(4), y1(4), y2(4);
    map<pair<int, int>, int> mp;
    for(int i = 0; i < 4; i++)
    {
        int temp = 0;
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
    for(int i = 0; i < 4; i++)
    {
        mp[{x1[i], y1[i]}]++;
        mp[{x2[i], y2[i]}]++;
    }
    int x = 0, y = 0;
    for(int i = 0; i < 4;i++)
    {
        if(x1[i] == x2[i])
            x++;
        else if(y1[i] == y2[i])
            y++;
    }
    debug(mp.size(), x, y, x1, y1, x2, y2);
    if(x != 2 || y != 2)
    {
        cout << "NO";
        return;
    }
    if(mp.size() == 4)
    {
        for(auto i : mp)
        {
            if(i.second > 2)
            {
                cout << "NO";
                return;
            }
        }
        cout << "YES";
        return;
    }
    cout << "NO";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    // cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

