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
const int MAXN = 5e5 + 10;
 
int a[MAXN];
long long sum[MAXN];
void solve()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    if (sum[n] % 3 != 0)
    {
        printf("0\n");
        return;
    }
    long long value = sum[n] / 3, ans = 0, cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (sum[i] != 2 * value)
        {
            if (sum[i] == value)
                cnt++;
            continue;
        }
        ans += cnt;
        if (sum[i] == value)
            cnt++;
    }
    cout <<ans;
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

