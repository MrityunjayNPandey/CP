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
    //THE FUCK I DONT KNOW ANY OF THIS
    int n, k;
    cin >> n >> k;
    vector<int> v(1, 1);
    k -= n;
    int curr = 2;
    for (int i = 2; i <= n; i++)
    {
        if (k < v.size())
        {
            int t = v[v.size() - k - 1];
            v.push_back(t);
            break;
        }
        k -= v.size();
        v.push_back(curr);
        curr++;
    }
    debug(v)
    while (v.size() < n)
    {
        v.push_back(v.back());
    }
    debug(v)
    for (auto x : v)
    {
        cout << x << " ";
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

