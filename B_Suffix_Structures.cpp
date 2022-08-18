/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 26-05-2022 01:01:48
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
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long

vector<int> position(26, -1);
bool cmp(pair<char, int>& char1, pair<char, int>& char2)
{
    return position[char1.first - 'a'] < position[char2.first - 'a'];
}

void solve()
{
    string s, t;
    cin >> s >> t;
    vector<int>a(26), b(26);
    for(int i = 0; i < s.size(); i++)
        a[s[i] - 'a']++;
    for(int i = 0; i < t.size(); i++)
    {
        b[t[i] - 'a']++;
        if(b[t[i] - 'a'] > a[t[i] - 'a'])
        {
            cout << "need tree";
            return;
        }
    }
    if(s.size() == t.size() && s != t)
    {
        cout << "array"; return;
    }
    for(int i = 0, j = 0; i < s.size();)
        if(s[i] != t[j])
        {
            s.erase(i, 1);
        } else i++, j++;
    cout << (s == t ? "automaton" : "both");
    // int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    // string str, str1;
    // cin >> str >> str1;
    // debug(str1.length())
    // int array = 0, automation = 0;
    // if(str.length() > str1.length())
    //     automation++;
    // else if(str1.length() > str.length())
    // {
    //     cout << "need tree";
    //     return;
    // }
    // map<char, int> mp, mp1;
    // for(int i = 0; i < str.length(); i++)
    // {
    //     mp1[str[i]]++;
    // }
    // for(int i = 0; i < str1.length(); i++)
    // {
    //     if(!mp1[str1[i]])
    //     {
    //         cout << "need tree";
    //         return;
    //     }
    //     mp[str1[i]]++;
    // }
    // map<char, deque<int>> mpv;
    // vector<pair<char, int>> vp;
    // for(int i = 0; i < str.length(); i++)
    // {
    //     if(mp[str[i]] > 0)
    //     {
    //         vp.pb({ str[i], i });
    //         mpv[str[i]].pb(i);
    //     }
    // }
    // debug(mpv);
    // int t = 0;
    // for(int i = 0; i < str1.length(); i++)
    // {
    //     int j = mpv[str1[i]][0];
    //     k = 0;
    //     while(j < t)
    //     {
    //         mpv[str1[i]].pop_front();
    //         if(!mpv[str1[i]].size())
    //         {
    //             array++;
    //             k++;
    //             break;
    //         }
    //         j = mpv[str1[i]][0];
    //     }
    //     debug(j, t)
    //         if(k) break;
    //     t = j;
    // }
    // if(array && automation)
    //     cout << "both";
    // else if(array) cout << "array";
    // else cout << "automaton";
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

