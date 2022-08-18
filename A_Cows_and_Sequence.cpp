/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 16-02-2022 08:16:19
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
// #define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
// #define int long long
int I;

void solve()
{
    int n;cin >> n;
    int t = n;
    // vector<int> v(n+1);
    int v[n + 1];
    int m[n + 1];
    for(int i = 0;i <= n;i++)
    {
        v[i] = 0;m[i] = 0;
    }
    // vector<int> m(n+1);
    int s = 1;
    double sum = 0;
    while(t--)
    {
        int q;cin >> q;
        if(q == 1)
        {
            int x, a;cin >> a >> x;
            m[a - 1] += x;
            sum += (double)x * (double)a;
        } else if(q == 2)
        {
            int k;cin >> k;
            v[s] = k;s++;
            sum += (double)k;
        } else
        {
            m[s - 2] += m[s - 1];
            sum -= (double)v[s - 1];
            sum -= (double)m[s - 1];
            m[s - 1] = 0;v[s - 1] = 0;
            s--;
        }
        double ans = (sum / ((double)(s)));
        printf("%.6lf\n", ans);
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
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
        // cout << endl;
    }
}

