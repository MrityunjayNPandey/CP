/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 13-05-2022 16:04:41
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
const long long INF = 1ll << 32; const long long N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long

vector<int >isprime(N, true);
vector<int >prime;
vector<int >SPF(N);
map<int, int> mp;

void manipulated_seive()
{
    isprime[0] = isprime[1] = false;

    for(int i = 2; i < N; i++)
    {
        if(isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }
        for(int j = 0;j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i];j++)
        {
            isprime[i * prime[j]] = false;
            SPF[i * prime[j]] = prime[j];
        }
    }
    for(auto i : prime)
    {
        mp[pow(i, 2)]++;
    }
}


void solve()
{
    int x, k = 0;
    cin >> x;
    if(mp[x] > 0)
        cout << "YES";
    else
        cout << "NO";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        manipulated_seive();
        int Test = 1;
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }

}