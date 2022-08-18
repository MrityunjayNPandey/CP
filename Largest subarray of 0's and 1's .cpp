/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 16-02-2022 03:12:55
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
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
int I;

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> v;
    unordered_map<int, int> mp, mp1;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x == 0)
            ans += -1;
        else
            ans++;
        v.pb(ans);
        if(mp[ans] == 0)
        {
            mp[ans]++;
            mp1[ans] = i;
        }
        if(mp[ans] > 0)
        {
            cnt = max(cnt, abs(i - mp1[ans]));
            debug(cnt)
        }
        if(ans == 0)
            k = i;
    }
    debug(mp, mp1, v, cnt)
        cout << max(k, cnt);
}

signed main()
{
    ios;
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    cin >> Test;
    for(I = 1; I <= Test; I++)
    {
#ifdef DEBUG
        clog << "-------" << I << "-------" << endl;dclear();
#endif
        solve();
        cout << endl;
    }
}

