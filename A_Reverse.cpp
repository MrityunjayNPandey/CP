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
//A_Reverse.cpp
void solve()
{
    int n = 0, m = 0, k = 0, ans = 0;
    cin >> n;
    vector<pair<int, int> >v, v1;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        v1.pb({ x, i });
        v.pb({ x, i });
    }
    sort(all(v));
    debug(v, v1)
    int p = 0, q = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].first != v1[i].first)
        {
            p = v[i].second;
            q = v1[i].second;
            break;
        }
    }
    debug(p, q)
    vector<int> va;
    for(int i = 0; i < q; i++)
    {
        va.pb(v1[i].first);
    }
    for(int i = p; i >= q; i--)
    {
        va.pb(v1[i].first);
    }
    for(int i = p + 1; i <= n; i++)
    {
        va.pb(v1[i].first);
    }
    for(int i = 0; i < n; i++)
    {
        cout << va[i] << " ";
    }
}

int32_t main()
{
    ios;
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    cin >> Test;
    for(I = 1; I <= Test; I++)
    {
        cerr << "-------" << I << "-------" << endl;dclear();
        solve();
        cout << endl;
    }
}

