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
    vector<int> v[4];
    vector<pair<int, int>> vp;
    unordered_map<int, int> mp;
    int w = 0, h = 0, v1, v2, h1, h2, maxb = 0, maxh = 0;
    cin >> w >> h;
    cin >> v1;
    for (int i = 0; i < v1; i++)
    {
        int x;
        cin >> x;
        v[0].pb(x);
    }
    debug(w, h)
    maxb = max(maxb, v[0][v1 - 1] - v[0][0]);
    debug(maxb);
    cin >> v2;
    for (int i = 0; i < v2; i++)
    {
        int x;
        cin >> x;
        v[1].pb(x);
    }
    maxb = max(maxb, v[1][v2 - 1] - v[1][0]);
    int maxa = maxb * h;
    debug(maxb, maxa);
    cin >> h1;
    for (int i = 0; i < h1; i++)
    {
        int x;
        cin >> x;
        v[2].pb(x);
    }
    maxh = max(maxh, v[2][h1 - 1] - v[2][0]);
    debug(maxh);
    cin >> h2;
    for (int i = 0; i < h2; i++)
    {
        int x;
        cin >> x;
        v[3].pb(x);
    }
    maxh = max(maxh, v[3][h2 - 1] - v[3][0]);
    int maxa1 = maxh * w;
    debug(maxh, maxa1);
    cout << max(maxa, maxa1);
}

// clang-format off
int32_t main()
{
    ios;
    #ifdef LOCALSUBLIME
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

