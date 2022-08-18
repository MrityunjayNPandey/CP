/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 15-04-2022 21:26:15
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
    string str1, str2;
    cin >> str1 >> str2;
    map<char, int> mp;
    map<char, vector<int>> vmp;
    for(int i = 0; i < str1.length(); i++)
    {
        mp[str1[i]]++;
        vmp[str1[i]].pb(i);
    }
    for(int i = 0; i < str2.length(); i++)
    {
        if(!mp[str2[i]])
        {
            cout << -1;
            return;
        }
    }
    ans = 1;
    int init = vmp[str2[0]][0];
    if(init == str1.length() - 1)
        init = -1;
    for(int i = 1; i < str2.length(); i++)
    {
        int j = 0;
        k = 0;
        int lb = upper_bound(vmp[str2[i]].begin(), vmp[str2[i]].end(), init) - vmp[str2[i]].begin();
        if(lb<vmp[str2[i]].size())
        {
            if(vmp[str2[i]][lb] > init)
            {
                if(init == -1)
                    ans++;
                init = vmp[str2[i]][lb];
                if(init == str1.length() - 1)
                    init = -1;
                k++;
            }
        }
        if(k == 0)
        {
            ans++;
            init = vmp[str2[i]][0];
        }
        debug(init, str2[i], i, k, ans);
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
    // cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

