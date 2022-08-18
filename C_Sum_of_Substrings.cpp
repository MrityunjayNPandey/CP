/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 31-05-2022 20:55:17
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

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    string str;
    cin >> str;
    for(int i = n - 1; i >= 0; i--)
    {
        if(str[i] == '1')
        {
            k -= n - 1 - i;
            if(k < 0)
            {
                k += n - 1 - i;
                break;
            }
            swap(str[i], str[n - 1]);
            break;
        }
    }
    for(int i = 0; i < n - 1; i++)
    {
        if(str[i] == '0' && str[i + 1] == '1')
            ans++;
        else if(str[i] == '1' && str[i + 1] == '0')
            ans += 10;
        else if(str[i] == '1' && str[i + 1] == '1')
            ans += 11;
    }
    debug(str);
    int ans1 = ans;
    ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == '1')
        {
            k -= i;
            if(k < 0)
            {
                k += i;
                break;
            }
            swap(str[0], str[i]);
            break;
        }
    }
    debug(str);
    for(int i = 0; i < n - 1; i++)
    {
        if(str[i] == '0' && str[i + 1] == '1')
            ans++;
        else if(str[i] == '1' && str[i + 1] == '0')
            ans += 10;
        else if(str[i] == '1' && str[i + 1] == '1')
            ans += 11;
    }
    cout << min(ans, ans1);
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

