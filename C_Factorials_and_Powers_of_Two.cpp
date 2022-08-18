/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 04-03-2022 22:03:09
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
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 63 - __builtin_clzll(n)
const long long INF = LONG_LONG_MAX; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long

vector<int> factorial, pow2, seq, seq2;
vector<pair<int, int>> factsum;
map<int, int> mp;

void pref()
{
    factorial.pb(1);
    pow2.pb(1);
    mp[1]++;
    for(int i = 1; i < 40; i++)
    {
        factorial.pb(factorial[i - 1] * i);
        mp[factorial[i]]++;
        if(factorial[i] > 1e12)
        {
            mp.erase(factorial[i]);
            break;
        }
    }
    int p = 1;
    mp.erase(1), mp.erase(2);
    for(auto i : mp)
    {
        seq.pb(i.first);
    }
    debug(seq)
        int total = 1 << 14;
    for(int i = 0; i < total; i++)
    {
        int sum = 0;
        int t = 0;
        for(int j = 0; j < 14; j++)
            if(i & (1 << j))
                sum += seq[j], t++;
        if(sum)
            factsum.pb({ sum, t });
    }
    factsum.pb({ 0, 0 });
    sort(all(factsum));
    for(int i = 0; i < factsum.size(); i++)
    {
        seq2.pb(factsum[i].first);
    }
}

void solve()
{
    int_fast32_t t = LONG_LONG_MAX;
    cout << t << endl;
    int n = 0, m = 0, k = 0, ans = INF, cnt = 0, sum = 0;
    cin >> k;
    debug(seq2[upper_bound(seq2.begin(), seq2.end(), k) - seq2.begin() - 1]);
    for(int i = upper_bound(seq2.begin(), seq2.end(), k) - seq2.begin() - 1; i >= 0; i--)
    {
        ans = min(ans, factsum[i].second + __builtin_popcountll(k - factsum[i].first));
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        pref();
    int Test = 1;
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

