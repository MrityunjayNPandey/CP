/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 07-05-2022 16:30:29
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
    cin >> n;
    string str;
    cin >> str;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        char a;
        cin >> a;
        debug(a)
            for(auto& i : str)
            {
                if(i == a)
                    i = '1';
            }
    }
    for(auto& i : str)
    {
        if(i != '1')
            i = '0';
    }
    debug(str)
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == '0')
                cnt++;
            if(str[i] == '1')
            {
                if(k == 0)
                {
                    k++;
                    ans = max(ans, cnt);
                } else
                    ans = max(ans, cnt + 1);
                cnt = 0;
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

