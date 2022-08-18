/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 03-05-2022 15:07:15
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

bool endsWith(std::string const& str, std::string const& suffix)
{
    if(str.length() < suffix.length())
    {
        return false;
    }
    return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
}

void solve()
{
    int  m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    string str;
    getline(cin, str);
    vector<string> vstr;
    string vtemp = {};
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ')
        {
            vstr.pb(vtemp);
            vtemp = {};
        } else
            vtemp += str[i];
    }
    vstr.pb(vtemp);
    debug(vstr);
    vtemp = {};
    string madj = "lios", fadj = "liala", mnoun = "etr", fnoun = "etra", mverb = "initis", fverb = "inites";
    int ms = 0, fs = 0, a = 0, n = 0, v = 0;
    for(int i = 0; i < vstr.size(); i++)
    {
        if(endsWith(vstr[i], madj))
        {
            ms = 1;
            a++;
            if(n != 0 || v != 0)
            {
                cout << "NO";
                return;
            }
        } else if(endsWith(vstr[i], fadj))
        {
            fs = 1;
            a++;
            if(n != 0 || v != 0)
            {
                cout << "NO";
                return;
            }
        } else if(endsWith(vstr[i], mnoun))
        {
            ms = 1;
            if(n != 0 || v != 0)
            {
                cout << "NO";
                return;
            }
            n++;
        } else if(endsWith(vstr[i], fnoun))
        {
            fs = 1;
            if(n != 0 || v != 0)
            {
                cout << "NO";
                return;
            }
            n++;
        } else if(endsWith(vstr[i], mverb))
        {
            ms = 1;
            if(n == 0)
            {
                cout << "NO";
                return;
            }
            v++;
        } else if(endsWith(vstr[i], fverb))
        {
            fs = 1;
            if(n == 0)
            {
                cout << "NO";
                return;
            }
            v++;
        }
        else
        {
            debug(vstr[i])
            cout << "NO";
                return;
        }
    }
    debug((v))
    if((ms && fs) || (v && !n))
    {
        cout << "NO";
        return;
    }
    cout << "YES";
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

