/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 09-04-2022 20:24:15
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
const long long MOD = 1e9 + 7; const long long mod = 32768;
#define int long long

vector<int> v[mod + 8], a(mod + 8, -1);
queue<int> q;

void pref()
{
    for(int i = 0; i < mod; i++)
    {
        v[(i + 1) % mod].pb(i);
        v[(i * 2) % mod].pb(i);
    }
    a[0] = 0;
    q.push(0);
    int temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        for(int i : v[temp])
            if(a[i] == -1)
            {
                a[i] = a[temp] + 1;
                q.push(i);
            }
    }
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cout << a[temp] << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        pref();
    int Test = 1;
// cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

