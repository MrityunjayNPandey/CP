/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 26-04-2022 23:52:07
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
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> c(n + 1, 0), r(n + 1, 0);
    vector<vector<int>> vv(n + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < n; i++)
    {
        int temp, temp1;
        cin >> temp >> temp1;
        r[temp] = 1;
        c[temp1] = 1;
        vv[temp][temp1] = 1;
    }
    debug(vv);
    k = n;
    vector<tuple<int, int, int>> vp;
    while(k)
    {
        for(int i = 1; i < k; i++)
        {
            if(c[i] == 0)
            {
                swap(c[i], c[k]);
                for(int j = 1; j <= n; j++)
                {
                    swap(vv[j][i], vv[j][k]);
                }
                vp.pb({ i, k, 2 });
                break;
            }
        }
        debug(vv)
            for(int i = k; i >= 0; i--)
            {
                int x1 = 0;
                if(c[i] == 1)
                {
                    if(vv[k][i] != 1)
                    {
                        for(int j = 1; j < k; j++)
                        {
                            debug(vv[j][i], j, i)
                                if(vv[j][i] == 1)
                                {
                                    swap(r[k], r[j]);
                                    swap(vv[k], vv[j]);
                                    vp.pb({ j, k ,1 });
                                    x1++;
                                    break;
                                }
                        }
                        if(x1>0)
                        break;
                    } else
                    {
                        break;
                    }
                }
            }
        k--;
    }
    debug(vp)
        cout << vp.size() << endl;
    for(int i = 0; i < vp.size(); i++)
    {
        cout << get<2>(vp[i]) << " " << get<0>(vp[i]) << " " << get<1>(vp[i]) << endl;
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
