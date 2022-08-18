/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 29-06-2022 00:31:35
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
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
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
#define int long long

//Linear Sieve, Time complexity of O(n). lp represents smallest prime factor.
const int N = 1000000;
vector<int> lp(N + 1);
vector<int> prime;
void linearSIEVE()
{
    for(int i = 2; i <= N; ++i)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;
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
    cin >> n;
    vector<int> v(n), v1(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < n; i++)
        cin >> v1[i];
    map<int, int> mp1, mp2;
    for(int i = 0; i < n; i++)
    {
        set<int> st;
        int c = lp[v[i]];
        st.insert(c);
        while(v[i] > 1)
        {
            if(v[i] % c == 0)
            {
                st.insert(c);
                v[i] /= c;
            } else c++;
        }
        for(auto i : st)
        {
            mp1[i]++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        set<int> st;
        int c = lp[v1[i]];
        st.insert(c);
        while(v1[i] > 1)
        {
            if(v1[i] % c == 0)
            {
                st.insert(c);
                v1[i] /= c;
            } else c++;
        }
        for(auto i : st)
        {
            mp2[i]++;
        }
    }
    debug(mp1, mp2);
    for(auto i : mp1)
    {
        if(mp2[i.first] > 0)
        {
            ans += mp2[i.first] * i.second;
        }
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    // cin >> Test;
    linearSIEVE();
    for(int I = 1; I <= Test; I++)
    {
        solve();
        cout << endl;
    }
}

