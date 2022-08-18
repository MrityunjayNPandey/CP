/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 10-07-2022 11:47:03
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#define int long long
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define print(x)
#define dclear(x)
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 3e7 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

//Sieve of Eratosthenes, time complexity of O(N*log(logN))
vector<int> primetemp(MAX_N + 1, 1), ifprime(MAX_N + 1, 0), prime;
void SIEVE()
{
    prime.pb(1);
    ifprime[1]++;
    for(int p = 2; p <= MAX_N; p++)
    {
        if(primetemp[p] == 1)
        {
            prime.pb(p);
            ifprime[p]++;
            for(int i = p * p; i <= MAX_N; i += p)
            {
                primetemp[i] = 0;
            }
        }
    }
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<int, int>> vp, vp1;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int p = v[-1];
    debug(v);
    for(int i = 0; i < n; i++)
    {
        int k = 1;
        while(v[i] % m == 0)
        {
            k *= m;
            v[i] /= m;
        }
        if(vp.size())
        {
            if(vp.back().first == v[i])
                vp.back().second += k;
            else
                vp.pb({ v[i], k });
        } else
            vp.pb({ v[i], k });
    }
    cin >> k;
    vector<int> v1(k);
    for(int i = 0; i < k; i++)
        cin >> v1[i];
    debug(vp, v1);
    int t = 0;
    for(int i = 0; i < k; i++)
    {
        int t = 1;
        while(v1[i] % m == 0)
        {
            t *= m;
            v1[i] /= m;
        }
        if(vp1.size())
        {
            if(vp1.back().first == v1[i])
                vp1.back().second += t;
            else
                vp1.pb({ v1[i], t });
        } else
            vp1.pb({ v1[i], t });
    }
    if(vp.size() != vp1.size())
    {
        cout << "No";
        return;
    }
    for(int i = 0; i < (int)vp.size(); i++)
    {
        if(vp[i].first != vp1[i].first || vp[i].second != vp1[i].second)
        {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        SIEVE();
    int Test = 1;
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

