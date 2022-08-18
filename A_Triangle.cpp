/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 26-02-2022 02:37:26
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
    int a, b;
    cin >> a >> b;
    int x1, x2, y1, y2;
    bool found = false;
    int g = __gcd(a, b);
    for(int x = 1;x < g && !found;x++)
    {
        for(int y = 1;y < g && !found;y++)
        {
            if(x * x + y * y == g * g)
            {
                x1 = x * (a / g), y1 = y * (a / g);
                x2 = -y * (b / g), y2 = x * (b / g);

                if(y1 != y2)
                {
                    found = true;
                }
            }
        }
    }

    if(found)
    {
        cout << "YES" << endl;
        cout << 0 << " " << 0 << endl;
        cout << x1 << " " << y1 << endl;
        cout << x2 << " " << y2 << endl;
    } else cout << "NO";
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

