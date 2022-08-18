/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 25-02-2022 22:49:29
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

int mx = 1000;
vector<int> v;
void luck(long long n)
{
    if(n > mx) return;
    v.push_back(n);
    debug(n);
    luck(n * 10 + 4);
    luck(n * 10 + 7);
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    luck(0);
    debug(v);
    cin >> n;
    for(int i = 1; i < v.size(); i++)
    {
        if(n % v[i] == 0)
        {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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

