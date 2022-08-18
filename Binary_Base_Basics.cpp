// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef joKer
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
    cin >> n >> k;
    string str;
    cin >> str;
    l = 0, r = str.length()-1;
    while (l <= r)
    {
        if (str[l] != str[r])
        {
            ans++;
        }
        l++;
        r--;
    }
    if (k - ans >= 0 && (k - ans) % 2 == 0)
    {
        cout << "YES";
    }
    else if (k - ans >= 0 && n % 2 == 1)
    {
        cout << "YES";
    }
    else
        cout << "NO";
}

// clang-format off
int32_t main()
{
    ios;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef joKer
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}
