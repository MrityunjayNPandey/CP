/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 13-04-2022 14:42:45
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
    int t1;
    t1 = LONG_LONG_MAX;
    cout << t1;;
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    int x1, y1, x2, y2, x3, y3;
    vector<pair<int, int>> vp;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    vector<pair<int, int>> vp1 = { {x1, y1}, {x2, y2}, {x3, y3} };
    int x = min(y1, min(y2, y3));
    int y = max(y1, max(y2, y3));
    int xy = min(x1, min(x2, x3));
    int yx = max(x1, max(x2, x3));
    if(x1 == x2 || x1 == x3)
    {
        if(x2 == x3)
        {
            k = 1;
            vp.push_back({ x1,x });
            vp.push_back({ x1,y });
            return;
        } else
        {
            k = 2;
        }
    }
    if(y1 == y2 || y1 == y3)
    {
        if(y2 == y3)
        {
            k = 1;
            vp.push_back({ min(x1, min(x2, x3)), y1 });
            vp.push_back({ max(x1, max(x2, x3)), y1 });
            return;
        } else
        {
            k = 2;
        }
    }
    if(k == 1)
    {
        cout << 1 << endl;
        cout << vp[0].first << " " << vp[0].second << " " << vp[1].first << " " << vp[1].second;
        return;
    }
    if(k == 2)
    {
        cout << 2 << endl;
        if(x1 == x2 || x1 == x3)
        {

            if(x1 == x2)
            {
                vp.pb({ x1,x });
                vp.pb({ x1,y });
                vp.pb({ x1, y3 });
                vp.pb({ x3, y3 });
            } else if(x1 == x3)
            {
                vp.pb({ x1,x });
                vp.pb({ x1,y });
                vp.pb({ x1, y2 });
                vp.pb({ x2, y2 });
            } else if(y1 == y2)
            {
                vp.pb({ xy,y1 });
                vp.pb({ yx,y1 });
                vp.pb({ x3, y1 });
                vp.pb({ x3, y3 });
            } else if(y1 == y3)
            {
                vp.pb({ xy,y1 });
                vp.pb({ yx,y1 });
                vp.pb({ x2, y1 });
                vp.pb({ x2, y2 });
            }
        }
        cout << vp[0].first << " " << vp[0].second << " " << vp[1].first << " " << vp[1].second << endl;
        cout << vp[2].first << " " << vp[2].second << " " << vp[3].first << " " << vp[3].second << endl;
        return;
    }
    sort(all(vp1));
    cout << 3 << endl;
    cout << vp1[0].first << " " << vp1[0].second << " ";
    cout << vp1[0].first << " " << vp1[1].second << " " << endl;
    cout << vp1[0].first << " " << vp1[1].second << " ";
    cout << vp1[2].first << " " << vp1[1].second << " " << endl;
    cout << vp1[2].first << " " << vp1[1].second << " ";
    cout << vp1[2].first << " " << vp1[2].second << " " << endl;

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

