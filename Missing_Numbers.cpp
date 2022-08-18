/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 27-03-2022 13:54:55
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
    vector<int> v;
    for(int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;
        v.pb(temp);
    }
    sort(all(v));
    int a1 = (v[2] + v[0]) / 2;
    int b1 = v[2] - a1;
    int a2 = (v[2] + v[1]) / 2;
    int b2 = v[2] - a2;
    int a3 = (v[3] + v[0]) / 2;
    int b3 = v[3] - a3;
    int a4 = (v[3] + v[1]) / 2;
    int b4 = v[3] - a4;
    if((a1 % 1 == 0) && (a1 != 0) && (b1 % 1 == 0) && (b1 != 0))
        if((a1 / b1 == v[1]) && (a1 * b1 == v[3]) && (a1 >= 1) && (b1 >= 1) && (a1 <= 10000) && (b1 <= 10000))
        {
            cout << a1 << " " << b1;
            return;
        }
    if((a2 % 1 == 0) && (a2 != 0) && (b2 % 1 == 0) && (b2 != 0))
        if((a2 / b2 == v[0]) && (a2 * b2 == v[3]) && (a2 >= 1) && (b2 >= 1) && (a2 <= 10000) && (b2 <= 10000))
        {
            cout << a2 << " " << b2;
            return;
        }
    if((a3 % 1 == 0) && (a3 != 0) && (b3 % 1 == 0) && (b3 != 0))
        if((a3 / b3 == v[1]) && (a3 * b3 == v[2]) && (a3 >= 1) && (b3 >= 1) && (a3 <= 10000) && (b3 <= 10000))
        {
            cout << a3 << " " << b3;
            return;
        }
    if((a4 % 1 == 0) && (a4 != 0) && (b4 % 1 == 0) && (b4 != 0))
        if((a4 / b4 == v[0]) && (a4 * b4 == v[2]) && (a4 >= 1) && (b4 >= 1) && (a4 <= 10000) && (b4 <= 10000))
        {
            cout << a4 << " " << b4;
            return;
        }
    cout << "-1 -1";
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

