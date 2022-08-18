/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 06-05-2022 21:20:10
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
    string str;
    cin >> str;
    stack<pair<int, int>> st;
    vector<pair<int, int>> vp;
    vector<int> v(str.length(), 0);
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')
        {
            st.push({ '(', i });
        } else if(str[i] == '[')
        {
            st.push({ '[', i });
        } else if(str[i] == ')')
        {
            if(st.size() && st.top().first == '(')
            {
                v[st.top().second] = 1;
                v[i] = 1;
                st.pop();
            } else
                st.push({ ')', i });
        } else if(str[i] == ']')
        {
            if(st.size() && st.top().first == '[')
            {
                v[st.top().second] = 1;
                v[i] = 1;
                st.pop();
            } else
                st.push({ ']', i });
        }
    }
    debug(v);
    k=0;
    int init, final;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == 1 && k == 0)
        {
            init = i;
            k++;
            debug(init)
        } else if(v[i] == 0 && k)
        {
            final = i - 1;
            k = 0;
            vp.pb({ init, final });
        }
    }
    if(k)
    {
        vp.pb({init, v.size() - 1});
        k=0;
    }
    debug(vp);
    int mxstr = 0;
    pair<int, int> ans1;
    for(int i = 0; i < vp.size(); i++)
    {
        for(int j = vp[i].first; j <= vp[i].second; j++)
        {
            if(str[j] == '[')
                cnt++;
        }
        if(cnt >= ans)
        {
            if(cnt == ans)
            {
                if(mxstr < vp[i].second - vp[i].first)
                {
                    mxstr = vp[i].second - vp[i].first;
                    ans = cnt;
                    ans1 = { vp[i].first, vp[i].second };
                }
            } else
            {
                ans = cnt;
                ans1 = { vp[i].first, vp[i].second };
            }
        }
        cnt = 0;
    }
    debug(ans, ans1, str[ans1.first])
        cout << ans << endl;
    if(ans == 0)
        return;
    for(int i = ans1.first; i <= ans1.second; i++)
    {
        cout << str[i];
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

