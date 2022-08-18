/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 20-03-2022 11:50:10
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
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == '?') v.pb(i);
    }
    bool ans = true;
    function<void(string, int)> f = [&](string s, int p)
    {
        debug(s)
        if(p > v.size() + 1 || ans == false) return;
        if(p == v.size() + 1)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = i + 4; j < n; j++)
                {
                    int x = i, y = j;
                    bool fd = true;
                    while(x < y)
                    {
                        if(s[x] != s[y])
                        {
                            fd = false;
                            break;
                        }
                        x++;
                        y--;
                    }
                    if(fd == true) return;
                }
            }
            ans = false;
        } else
        {
            s[v[p - 1]] = '0';
            f(s, p + 1);
            s[v[p - 1]] = '1';
            f(s, p + 1);
        }
    };
    f(str, 1);
    cout << (ans ? "IMPOSSIBLE" : "POSSIBLE");
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
        cout << "Case #" << I << ": ";
        dclear(I);
        solve();
        cout << endl;
    }
}

