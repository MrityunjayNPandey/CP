/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 14-05-2022 16:20:28
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
const long long INF = 1ll << 32; const long long MAX_N = 1e5 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0, cntr[200005], cntc[200005];
    cin >> n >> m;
    int x, y;
    map<int, int> mpx, mpy;
    for(int i = 1; i <= n; i++)
    {
        mpx[i]++;
        mpy[i]++;
    }
    debug(mpx, mpy);
    for(int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int p, q;
            cin >> p >> q;
            ++cntr[p], ++cntc[q];
            mpx.erase(p);
            mpy.erase(q);
        } else if(t == 2)
        {
            int p, q;
            cin >> p >> q;
            --cntr[p], --cntc[q];
            if(!cntr[p])mpx[p]++;
            if(!cntc[q])mpy[q]++;
        } else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            auto it = mpx.lower_bound(x1);
            int pq = 0, qp = 0;
            if((*it).first <= x2 && (*it).first >= x1)
            {
                pq++;
            }
            auto it1 = mpy.lower_bound(y1);
            if((*it1).first <= y2 && (*it1).first >= y1)
            {
                qp++;
            }
            if(!pq || !qp)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
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

