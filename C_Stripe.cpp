/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 15-02-2022 20:41:27
**/
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
const int_fast32_t INF = 1ll << 32; const int_fast32_t MAX_N = 1e6 + 7;
const int_fast32_t MOD = 1e9 + 7; const int_fast32_t mod = 998244353;
#define int int_fast32_t
int I;

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        k += x;
        v.pb(k);
    }
    debug(k)
    for(int i = 0; i < n-1; i++)
    {
        if(v[i] == k - v[i])
        {
            ans++;
            debug(v[i], i)
        }
    }
    debug(v, ans)
        cout << ans;
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
#ifdef DEBUG
        clog << "-------" << I << "-------" << endl;dclear();
#endif
        solve();
        cout << endl;
    }
}

