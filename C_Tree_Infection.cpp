/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 07-06-2022 16:04:57
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
int ans;
void proc(vector<int>& a)
{
    if(a.empty()) return;
    int n = a.size();
    int last = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == a[0])
        {
            last = i;
        } else
        {
            break;
        }
    }
    --a[last];
    for(int i = 0; i < n; ++i) --a[i];
    ++ans;
    while(!a.empty() && a.back() <= 0)
    {
        a.pop_back();
    }
    proc(a);
}


void solve()
{
    ans = 0;
    int n = 0, m = 0, k = 0, cnt = 0, sum = 0;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> v;
    for(auto i : mp)
    {
        v.pb(i.second);
    }
    sort(rall(v));
    v.pb(1);
    debug(v);
    for(int i = 0; i < v.size(); ++i)
    {
        v[i] = v[i] - (v.size() - i);
        ++ans;
    }
    sort(v.rbegin(), v.rend());
    while(!v.empty() && v.back() <= 0) v.pop_back();
    proc(v);
    debug(v, ans);
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

