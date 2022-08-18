/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 22-04-2022 01:00:11
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

//Sieve of Eratosthenes, time complexity of O(N*log(logN))
vector<int> primetemp(MAX_N, 1), ifprime(2*MAX_N, 0), prime;
void SIEVE()
{
    prime.pb(1);
    ifprime[1]++;
    for(int p = 2; p * p <= MAX_N; p++)
    {
        if(primetemp[p] == 1)
        {
            prime.pb(p);
            ifprime[p]++;
            for(int i = p * p; i <= MAX_N; i += p)
            {
                primetemp[i] = 0;
            }
        }
    }
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0, maxa = 0;
    string str;
    cin >> str;
    char x = '0';
    vector<char> v;
    map<char, int> mp;
    for(int i = 0; i < str.length(); i++)
    {
        mp[str[i]]++;
        if(maxa < mp[str[i]])
        {
            x = str[i];
            maxa = mp[str[i]];
        }
    }
    string tstr, astr;
    int t = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(i == 0)
        {
            t++;
        } else if(i + 1 > str.length() / 2)
        {
            if(ifprime[i + 1])
            {
                t++;
            }
        }
    }
    if(maxa < str.length() - t)
    {
        cout << "NO";
        return;
    }
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] != x)
        {
            tstr += str[i];
        }
    }
    while(tstr.length() <= t)
    {
        tstr += x;
    }
    int p = 0;
    cout << "YES" << endl;
    for(int i = 0; i < str.length(); i++)
    {
        if(i == 0)
        {
            cout << tstr[p];
            p++;
        } else if(i >= str.length() / 2)
        {
            if(ifprime[i + 1])
            {
                cout << tstr[p];
                p++;
            } else
                cout << x;
        } else
        {
            cout << x;
        }

    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        SIEVE();
    int Test = 1;
// cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

