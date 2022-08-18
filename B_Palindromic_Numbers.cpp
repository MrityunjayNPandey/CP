/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 19-06-2022 14:57:18
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
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
#define int long long

bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if(n1 < n2)
        return true;
    if(n2 < n1)
        return false;

    for(int i = 0; i < n1; i++)
        if(str1[i] < str2[i])
            return true;
        else if(str1[i] > str2[i])
            return false;

    return false;
}

string findDiff(string str1, string str2)
{
    if(isSmaller(str1, str2))
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    for(int i = 0; i < n2; i++)
    {

        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);

        if(sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        } else
            carry = 0;

        str.push_back(sub + '0');
    }

    for(int i = n2; i < n1; i++)
    {
        int sub = ((str1[i] - '0') - carry);

        if(sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        } else
            carry = 0;

        str.push_back(sub + '0');
    }

    reverse(str.begin(), str.end());

    return str;
}

void solve()
{
    int n = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    string m;
    cin >> m;
    string str;
    debug(m);
    if(m[0] == '9')
    {
        int x = n + 1;
        while(x--)
        {
            str.pb('1');
        }
        debug(str)
    } else
    {
        int x = n;
        while(x--)
        {
            str.pb('9');
        }
    }
        string str1 = findDiff(str, m), str2 = "";
        for(int i = 0; i < str1.size(); i++)
        {
            if(str1[i] != '0')
                k++;
            if(k) str2 += str1[i];
        }
        cout << str2;
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

