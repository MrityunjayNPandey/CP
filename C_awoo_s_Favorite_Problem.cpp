/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 12-06-2022 20:51:37
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
#define int long long

void solve()
{
    int n = 0, m = 0, k = 0, ans = LONG_LONG_MAX, cnt = INT_MAX, sum = 0;
    cin >> n;
    string str1, str2;
    cin >> str1 >> str2;
    if(n == 1)
    {
        if(str1[0] != str2[0]) cout << "NO";
        else cout << "YES";
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(str1[i] != str2[i])
        {
            if((str1[i] == 'a' && str2[i] == 'b') || (str1[i] == 'b' && str2[i] == 'c'))
            {
                int it = i;
                while(str1[it] == str1[i]) it++;
                if(it < n) swap(str1[i], str1[it]);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(str1[i] != str2[i])
        {
            cout << "NO";
            return;
        }
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
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << "\n";
    }
}

