/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 09-04-2022 21:29:11
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
#define LOG(n) 31 - __builtin_clz(n)
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long

void solve()
{
    int n = 0, m = 0, k = 0, ans = 1000000000000000000, cnt = 0, sum = 0;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.pb(temp);
        cnt = max(cnt, temp);
    }
    for(int it = cnt;it < cnt + 4; ++it)
    {
        int p = 0, q = 0;
        for(auto& i : v)
        {
            p += (it - i) / 2;
            q += (it - i) % 2;
        }
        int r1 = q + p * 2;
        int s1 = (r1 / 3) * 2;
        if(r1 % 3 == 2)
            s1 += 2;
        else if(r1 % 3 == 1)
            ++s1;
        ans = min(max(q * 2 - 1, s1), ans);
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
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

