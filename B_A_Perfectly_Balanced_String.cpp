/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 30-04-2022 20:31:11
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
    string str;
    cin >> str;
    // map<char, vector<int>> mp;
    // for(int i = 0; i < str.length(); i++)
    // {
    //     mp[str[i]].pb(i);
    // }
    // for(auto i : mp)
    // {
    //     if(i.second.size() > 1)
    //     {
    //         map<char, int> mp1;
    //         for(int k = 0; k < i.second.size() - 1; k++)
    //         {
    //             for(int j = i.second[k]; j < i.second[k + 1]; j++)
    //             {
    //                 mp1[str[j]]++;
    //             }
    //             if(mp1.size() != mp.size())
    //             {
    //                 cout << "NO";
    //                 return;
    //             }
    //         }
    //     }
    // }
    // cout << "YES";

    //MAA CHUDAE YE CODE

    map<char, int> mp;
    for(auto i : str)
    {
        mp[i]++;
    }
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] != str[i % mp.size()])
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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

