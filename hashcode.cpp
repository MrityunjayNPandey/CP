/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 25-02-2022 00:02:13
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

struct contri
{
    string contrebutor;
    int skillevel = 0;
};

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    int c, p;
    cin >> c >> p;
    map<string, contri> mp;
    for(int i = 0; i < c; i++)
    {
        string contreb;
        int skilno = 0;
        cin >> contreb >> skilno;
        for(int j = 0; j < skilno; j++)
        {
            string skillname;
            int sklvl = 0;
            cin >> skillname >> sklvl;
            if(sklvl > mp[skillname].skillevel)
            {
                mp[skillname].contrebutor = contreb;
                mp[skillname].skillevel = sklvl;
            }
        }
    }
    // for(auto i : mp)
    // {
    //     cout << i.first << " ";
    //     cout << i.second.skillevel << " " << i.second.contrebutor << endl;
    // }
    int maxscore;
    vector<string> vans;
    vector<vector<string>> vvans;
    for(int i = 0; i < p; i++)
    {
        string str;
        cin >> str;
        int d, s, b, r;
        cin >> d >> s >> b >> r;
        int t1 = 0;
        vector<string> vv;
        for(int j = 0; j < r; j++)
        {
            int sl;
            string skl;
            cin >> skl >> sl;
            if(mp[skl].skillevel < sl)
            {
                t1++;
            }
            vv.pb(mp[skl].contrebutor);
        }
        if(t1 == 0)
        {
            vans.pb(str);
            vvans.pb(vv);
            ans = max(ans, s);
            debug(s, str);
            cnt++;
        }
    }
    cout << cnt << endl;
    for(int i = 0; i < vvans.size(); i++)
    {
        cout << vans[i] << endl;
        for(int j = 0; j < vvans[i].size(); j++)
            cout << vvans[i][j] << endl;
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

