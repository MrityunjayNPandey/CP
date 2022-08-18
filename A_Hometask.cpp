/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 15-03-2022 17:52:39
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
    string str, astr;
    cin >> str;
    vector<string> vstr;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string strt;
        cin >> strt;
        vstr.pb(strt);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < str.length() - 1; j++)
        {
            if(str[i] == vstr[i][0] && str[i + 1] == vstr[i][1] || str[i] == vstr[i][1] && str[i + 1] == vstr[i][0])
            {
                if(astr.size() > 0)
                {
                    if(astr[astr.size() - 1] != str[j])
                    {
                        astr += str[j];j++;ans++;
                    } else if(astr[astr.size() - 1] != str[j + 1])
                    {
                        {
                            astr += str[j + 1];j++;ans++;
                        }
                    } else
                    {
                        ans += 2;
                        j += 2;
                    }
                }
            }
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
    // cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

