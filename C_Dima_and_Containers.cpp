/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 12-04-2022 20:50:29
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
    stack<int> st, deq;
    queue<int> q;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        if(x == 0)
        {
            k = 0;
            m = 0;
            if(!st.empty())
                k++;
            if(!deq.empty())
                k++;
            if(!q.empty())
                k++;
            cout << k << " ";
            if(!st.empty())
                cout << "popStack ", st.pop();
            if(!q.empty())
                cout << "popQueue ", q.pop();
            if(!deq.empty())
                cout << "popFront ", deq.pop();
            if(n != 0)
                cout << endl;
        } else
        {
            if(m % 3 == 0)
                cout << "pushStack ", st.push(x);
            if(m % 3 == 1)
                cout << "pushQueue ", q.push(x);
            if(m % 3 == 2)
                cout << "pushFront ", deq.push(x);
            if(n != 0)
                cout << endl;
            m++;
        }
    }
}////

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

