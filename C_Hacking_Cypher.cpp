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
#define ll long long
#define vll vector <long long>
void solve()
{
    string s;
    cin >> s;
    ll a, b;
    cin >> a >> b;
    ll n = s.length();
    vll mda(n, -1), mdb(n);
    ll rem = 0, p = 1;
    for (ll i = 0; i < n; i++)
    {
        rem = ((rem * 10) + s[i] - '0') % a;
        mda[i] = rem;
    }
    rem = 0;
    for (ll i = n - 1; i > 0; i--)
    {
        rem = (rem + (s[i] - '0') * p) % b;
        p = (p * 10) % b;
        if (rem == 0 && mda[i - 1] == 0 && s[i] != '0')
        {
            cout << "YES" << endl
                 << s.substr(0, i) << endl
                 << s.substr(i, n - i);
            return;
        }
    }


    
    cout << "NO";
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

