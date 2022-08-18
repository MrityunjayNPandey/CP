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
    int n = 0, m = 0, k = 0, ans = 0, p = 0, q = 0;
    cin >> n>>m;
    vector<int> tor(n), tol(n), v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.pb(x);
    }
    iota(tol.begin(), tol.end(), 0);
    iota(tor.begin(), tor.end(), 0);

    tol[0] = 0;
    for (int i = 1; i < n; ++i)
        if (v[i - 1] >= v[i])
            tol[i] = tol[i - 1];

    tor[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i)
        if (v[i] <= v[i + 1])
            tor[i] = tor[i + 1];
    for(int j = 0; j < m; j++)
    {
        int l, r;
        cin >> l >> r;
        l--;r--;
        cout << (tol[r] <= tor[l] ? "Yes" : "No") << '\n';
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
    for(I = 1; I <= Test; I++)
    {
        cerr << "-------" << I << "-------" << endl;dclear();
        solve();
        cout << endl;
    }
}

