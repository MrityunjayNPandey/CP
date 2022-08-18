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
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
int I;

void solve()
{
    int n;cin >> n;
    vector<int> v(n);
    for (int i = 0;i < n;i++)cin >> v[i];
    sort(v.begin(), v.end());
    if (n == 1)
    {
        cout << -1;
        return;
    }
    if (v[0] == v[n - 1])
    {
        cout << 1 << endl << v[0];
        return;
    }
    int d = v[1] - v[0];
    bool flag = true;
    for (int i = 1; i < n - 1; i++)
        if (v[i + 1] - v[i] != d)
        {
            flag = false;
            break;
        }
    int can = 0;
    if (flag)
    {
        if (n == 2 && d % 2 == 0)
        {
            cout << 3 << endl << v[0] - d << " " << v[0] + d / 2 << " " << v[1] + d;
        } else
        {
            cout << 2 << endl << v[0] - d << " " << v[n - 1] + d;
        }
        return;
    } else
    {
        d = min(d, v[n - 1] - v[n - 2]);
        for (int i = 1; i < n; i++)
            if (v[i] - v[i - 1] != d)
                if (can == 0 && v[i - 1] + d == v[i] - d)
                {
                    can = v[i - 1] + d;
                } else
                {
                    cout << 0;
                    return;
                }
    }
    cout << 1 << endl << can;
    return;
}

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

