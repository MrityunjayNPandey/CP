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
    int n = 0, k = 0, l = 0, r = 0, ans = 0;
    vector<int> v;
    vector<pair<int, int>> vp;
    unordered_map<int, int> mp;
    int x, cnt = 0;
    cin >> n >> x >> k;
    int w1 = x, w2 = x + 3;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.pb(temp);
        if (temp % 2 != 0)
        {
            cnt++;
        }
    }
    if (cnt % 2 != 0)
    {
        w1++;
        w2++;
    }
    if (k % 2 == 0)
    {
        if (w1 % 2 == 0)
            cout << "Alice";
        else
            cout << "Bob";
    }
    else
    {
        if (w1 % 2 != 0)
            cout << "Alice";
        else
            cout << "Bob";
    }
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

