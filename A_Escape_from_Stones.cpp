#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...)
#define dclear()
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
int I;

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0;
    string str;
    cin >> str;
    debug(str);
    double pos = 1, idx = 0;
    vector < pair<double, int>> v;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'r')
            cout << i + 1 << endl;
    }
    for (int i = str.length(); i >= 0; i--)
    {
        if (str[i] == 'l')
            cout << i + 1 << endl;
    }
}


int32_t main()
{
    ios;
#ifdef SUBLIME
    free
#endif
    int Test = 1;
    // cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        int arr[1000000];
        debug(arr[0]);
        cerr << "-------" << I << "-------" << endl;
        solve();
        cout << endl;
    }
}

