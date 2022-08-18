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
    int n = 0, m = 0, k = 0, ans = 0;
    cin >> n;
    vector<int> v, vodd, veven, v1;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.pb(x);
        v1.pb(x);
        if(x % 2 == 0)
            veven.pb(x);
        else
            vodd.pb(x);
    }
    debug(veven, vodd)
    sort(all(v1));
    if(v1 == v)
    {
        cout << "Yes";
        return;
    }
    for(int i = 1; i < veven.size(); i++)
    {
        if(veven[i] < veven[i - 1])
        {
            cout << "No";
            return;
        }
    }

    for(int i = 1; i < vodd.size(); i++)
    {
        if(vodd[i] < vodd[i - 1])
        {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int32_t main()
{
    ios;
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    cin >> Test;
    for(I = 1; I <= Test; I++)
    {
        clog << "-------" << I << "-------" << endl;dclear();
        solve();
        cout << endl;
    }
}

