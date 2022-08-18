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
    int n = 0, l = 0, r = 0, ans = 0;
    float p = 0;
    vector<int> v;
    vector<pair<int, int>> vp;
    unordered_map<int, int> mp;
    cin >> n >> p;
    string s1, s2;
    int k = ceil(p / 2), t = p;
    debug(k);
    for (int i = 0; i < k; i++)
    {
        if (t >= 2)
        {
            if (i != k - 1)
            {
                if (n == 0)
                {
                    cout << -1;
                    return;
                }
            }
            s1 += '1';
            s1 += '1';
            if (n > 0)
                s1 += '0';
            t -= 2;
            n--;
        }
        else
        {
            s1 += '1';
            if (n > 0)
                s1 += '0';
            t -= 1;
            n--;
        }
    }
    if (n > 0)
    {
        s2 += '0';
        n--;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == s1[i + 1] && n > 0)
            {
                s2 += '1';
                s2 += '0';
                n--;
            }
            else
            {
                s2 += s1[i];
            }
        }
    }
    if (n > 0)
    {
        cout << -1;
        return;
    }
    if (s2.length() == 0)
        cout << s1;
    else
        cout << s2;
}

// clang-format off
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
        #ifdef DEBUG
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}

