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
    int n = 0, k = 0, ans = 0, maxa = 0;
    cin >> n;
    vector<int> v;
    unordered_map<int, int> mp;
    for (int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        v.pb(x);
        mp[x]++;
        maxa = max(maxa, x);
    }
    debug(mp)
    int mex = 0;
    for (int i = 0; i <= maxa+1; i++)
    {
        if (mp[i] == 0)
        {
            debug(i)
            mex = i;
            break;
        }
    }
    debug(mex)
    if (mex == 0)
    {
        cout << "YES";
        return;
    }
    for (int i = 0; i < mex; i++)
    {
        if (mp[i] < 2)
        {
            cout << "NO";
            return;
        }
    }
    cout<<"YES";
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

