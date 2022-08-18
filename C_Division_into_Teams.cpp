/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 15-02-2022 15:21:41
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
const int_fast32_t INF = 1ll << 32; const int_fast32_t MAX_N = 1e6 + 7;
const int_fast32_t MOD = 1e9 + 7; const int_fast32_t mod = 998244353;
#define int int_fast32_t
int I;

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0;
    cin >> n;
    vector < pair<int, int> >v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.pb({ x, i });
    }
    sort(all(v));
    vector<int> t1, t2;
    for(int i = 0; i < v.size(); i++)
    {
        if(i % 2 == 0)
            t1.pb(v[i].second + 1);
        else
            t2.pb(v[i].second + 1);
    }
    cout << t1.size() << endl;
    for(int i = 0; i < t1.size(); i++)
    {
        cout << t1[i] << " ";
    }
    cout << endl << t2.size() << endl;
    for(int i = 0; i < t2.size(); i++)
    {
        cout << t2[i] << " ";
    }
}

int32_t main()
{
    ios;
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    // cin >> Test;
    for(I = 1; I <= Test; I++)
    {
#ifdef DEBUG
        clog << "-------" << I << "-------" << endl;dclear();
#endif
        solve();
        cout << endl;
    }
}

