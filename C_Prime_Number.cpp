// /**
// *      codeforces: _joKer_0
// *      codechef:  joker_0000
// *      created: 04-04-2022 21:23:00
// **/
// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #ifdef DEBUG
// #include "algo/debug.h"
// #else
// #define debug(...) 
// #define dclear(x)
// #endif
// #define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
// #define all(x) x.begin(), x.end()
// #define rall(x) x.rbegin(), x.rend()
// #define pb push_back
// #define LOG(n) 31 - __builtin_clz(n)
// const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
// const long long MOD = 1e9 + 7; const long long mod = 998244353;
// #define int long long

// int power(long long x, unsigned int y, int p)
// {
//     int res = 1;     // Initialize result
//     x = x % p; // Update x if it is more than or
//                 // equal to p
//     if(x == 0) return 0; // In case x is divisible by p;
//     while(y > 0)
//     {
//         // If y is odd, multiply x with result
//         if(y & 1)
//             res = (res * x) % p;
//         // y must be even now
//         y = y >> 1; // y = y/2
//         x = (x * x) % p;
//     }
//     return res;
// }

// void solve()
// {
//     int n = 0, m = 0, k = 0, ans = 1, cnt = 0, sum = 0, sum1 = 0;
//     cin >> n >> m;
//     vector<int> v, v1;
//     map<int, int> mp;
//     for(int i = 0; i < n; i++)
//     {
//         int temp;
//         cin >> temp;
//         v.pb(temp);
//         sum += temp;
//         mp[temp]++;
//     }
//     sort(all(v));
//     int igcd = sum - v[n - 1];
//     if(mp[v[n - 1]] % m == 0)
//     {
//         int x = mp[v[n - 1]];
//         while(x % m == 0)
//         {
//             x /= m;
//             igcd++;
//         }
//     }
//     cout << power(m, min(sum, igcd), MOD);
// }

// signed main()
// {
//     ios::sync_with_stdio(false); cin.tie(0);
// #ifdef SUBLIME
//     free
// #endif
//         int Test = 1;
//     // cin >> Test;
//     for(int I = 1; I <= Test; I++)
//     {
//         dclear(I);
//         solve();
//         cout << endl;
//     }
// }
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long li;

const li MOD = 1000000007;

li bpow(li x, li v)
{
    if(v == 0)
        return 1 % MOD;

    if(v % 2 == 1)
        return (x * bpow(x, v - 1)) % MOD;

    li r = bpow(x, v / 2);

    return (r * r) % MOD;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector < li > a(n), b;
    li sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < n; i++)
        b.push_back(sum - a[i]);
    sort(b.rbegin(), b.rend());


    while(true)
    {
        li v = b[b.size() - 1];

        int cnt = 0;
        while(b.size() > 0 && b[b.size() - 1] == v)
        {
            cnt++;
            b.pop_back();
        }

        if(cnt % x != 0)
        {
            v = min(v, sum);
            cout << bpow(x, v) << endl;
            return 0;
        } else
        {
            cnt /= x;
            for(int i = 0; i < cnt; i++)
                b.push_back(v + 1);
        }
    }
}

