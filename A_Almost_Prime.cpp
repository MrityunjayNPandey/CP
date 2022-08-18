// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end() 
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9+7; const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve()
{
    int n = 0, k = 0, l = 0, r = 0, ans = 0, x = 0;
    vector<int> v;
    vector<pair<int, int>> vp;
    unordered_map<int, int> mp;
    cin >> k >> x;
    int i = 1, t = 0;
    while (ans < x)
    {
        if (i <= 0)
            break;
        if (i == k)
        {
            t++;
        }
        if (t != 0)
        {
            ans += i;
            i--;
        }
        else
        {
            ans += i;
            i++;
        }
        l++;
        debug(ans, i)
    }
    cout << l;
}

// clang-format off
int32_t main()
{
    ios;
    #ifdef SUBLIME
    free
    #endif
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef DEBUG
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}

