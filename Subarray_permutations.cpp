// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef LOCAL
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
    int n = 0, k = 0, ans = 0;
    cin >> n >> k;
    if (k == 1)
    {
        if (n == 1)
            cout << 1;
        else
            cout << -1;
        return;
    }
    vector<int> v;
    for(int i = 0; i < n; i++)
    v.pb(i+1);
    k=n-k;
    for(int i = 1; i <= k; i++)
    {
        v[i]=v[i+1];
    }
    v[k+1]=2;
    for(int i = 0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
}

// clang-format off
int32_t main()
{
    ios;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef LOCAL
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}
