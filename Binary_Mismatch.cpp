/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 13-04-2022 22:02:44
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
    string str;
    cin >> str;
    map<int, int> mp;
    int no1 = 0, no0 = 0, ni1 = 0, ni0 = 0;
    if(n % 2 == 1)
    {
        cout << "NO";
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(str[i] == '0')
            no0++;
        else
            no1++;
    }
    ni1 = no1;
    ni0 = no0;
    if(no0 == no1)
    {
        cout << "YES" << endl;
        cout << 1 << " " << n;
    } else if(no0 > no1)
    {
        int init = 0;
        ans=no1;
        for(int i = 0; i < n; i++)
        {
            if(str[i] == '0')
            {
                ans++;
                if(ans == no0 - no1)
                {
                    debug(i)
                        cout << "YES" << endl;
                    cout << init << " " << i + 1;
                    return;
                }
            } else
                ans--;
            if(ans <= 0)
            {
                if(str[i] == '0')
                    init = i + 1;
                else
                    init = i + 2;
                ans = no1;
            }
        }
        cout << "NO";
    } else
    {
        int init = 1;
        ans=no0;
        for(int i = 0; i < n; i++)
        {
            if(str[i] == '1')
            {
                ans++;
                if(ans == no1 - no0)
                {

                    debug(i)
                        cout << "YES" << endl;
                    cout << init << " " << i + 1;
                    return;
                }
            } else
                ans--;
            if(ans <= 0)
            {
                if(str[i] == '1')
                    init = i + 1;
                else
                    init = i + 2;
                ans = no0;
            }
        }
        cout << "NO";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

