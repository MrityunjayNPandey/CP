/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 24-05-2022 22:15:17
**/
#include <bits/stdc++.h>
using namespace std;
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
#define LOG(n) 31 - __builtin_clz(n)
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
const int MAX = 5004;
int n, sum, s[MAX];
pair<int, int> a[MAX];
vector<int> ans;

void solve()
{
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i].first >> a[i].second;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < i;j++)
            if(a[i].first < a[j].second && a[j].first < a[i].second)
                s[i]++, s[j]++, sum++;
    for(int i = 0;i < n;i++)
        if(s[i] == sum)
            ans.push_back(i);
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i + 1 << ' ';

        // int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
        // cin >> n;
        // vector<pair<int, int>> vp;
        // for(int i = 0; i < n; i++)
        // {
        //     int x, y;
        //     cin >> x >> y;
        //     vp.pb({ x, i });
        //     vp.pb({ y, i });
        // }
        // sort(all(vp));
        // debug(vp);
        // int t = -1;
        // map<int, int> mp;
        // for(int i = 0; i < vp.size(); i++)
        // {
        //     mp[vp[i].second]++;
        //     if(t == -1)
        //     {
        //         if(mp[vp[i].second] == 1)
        //             t = vp[i].second;
        //         continue;
        //     }
        //     if(vp[i].second != t)
        //     {
        //         k++;
        //     } else
        //     {
        //         k = 0;
        //         t = -1;
        //     }
        //     debug(t, k, i);
        //     if(k >= 2)
        //     {
        //         cout << 0;
        //         return;
        //     }
        // }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    // cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

