/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 30-04-2022 13:14:52
 **/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...)
#define dclear(x)
#endif
#define free                            \
    freopen("input.txt", "r", stdin);   \
    freopen("output.txt", "w", stdout); \
    freopen("error.txt", "w", stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
const long long INF = 1ll << 32;
const long long MAX_N = 1e3 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
#define int long long

// limitation ki MKC

// Linear Sieve, Time complexity of O(n). lp represents smallest prime factor.
const int N = 10000000;
vector<int> lp(N + 1);
vector<int> prime;
void linearSIEVE()
{
    for(int i = 2; i <= N; ++i)
    {
        if(lp[i] == 0)
        {
            lp[i] = i
                prime.push_back(i);
        }
        for(int j = 0; j < (int)prime.size() && prime[j] <= lp[i] && i * prime[j] <= N; ++j)
        {
            lp[i * prime[j]] = prime[j];
        }
    }
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<int> num(n, 0), den(m, 0), nmult, dmult;
    map<int, int> numfact, denfact;
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
        auto primeFactors = [&](int n1)
        {
            while(n1 > 1)
            {
                int c = lp[n1];
                numfact[c]++;
                n1 /= c;
            }
        };
        primeFactors(num[i]);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> den[i];
        auto primeFactors = [&](int n1)
        {
            while(n1 > 1)
            {
                int c = lp[n1];
                denfact[c]++;
                n1 /= c;
            }
        };
        primeFactors(den[i]);
    }
    for(auto& i : numfact)
    {
        int mn = min(denfact[i.first], i.second);
        denfact[i.first] -= mn;
        i.second -= mn;
    }
    debug(numfact, denfact);
    vector<int> nans, dans;
    cout << n << " " << m << endl;
    for(int i = 0; i < n; i++)
    {

        int f = num[i], x = 1;
        while(f > 1)
        {
            if(numfact[lp[f]] > 0)
            {
                numfact[lp[f]]--;
                x *= lp[f];
            }
            f /= lp[f];
        }
        cout << x << " ";
    }
    cout << endl;
    for(int i = 0; i < m; i++)
    {

        int f = den[i], x = 1;
        while(f > 1)
        {
            if(denfact[lp[f]] > 0)
            {
                denfact[lp[f]]--;
                x *= lp[f];
            }
            f /= lp[f];
        }
        cout << x << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef SUBLIME
    free
#endif
        linearSIEVE();
    int Test = 1;
    // cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        // dclear(I);
        solve();
        cout << endl;
    }
}