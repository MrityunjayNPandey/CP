// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 99824435; const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(all(v));
    debug(v);
}

int32_t main()
{
    ios;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
#ifdef LOCAL
        cerr << "-------" << I << "-------" << nl;
#endif
        solve();
        cout << endl;
    }
}
