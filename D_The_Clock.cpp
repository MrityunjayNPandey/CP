/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 14-06-2022 20:46:11
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

void reverseStr(string& str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for(int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    string str, stra, strb;
    cin >> str;
    cin >> n;
    stra += str[0];
    stra += str[1];
    strb += str[3];
    strb += str[4];
    int a = stoi(stra);
    int b = stoi(strb);
    string init = stra + strb;
    debug(init)
    string tempstr = init;
    reverseStr(tempstr);
    if(tempstr == init)
        ans++;
    int p = n / 60;
    int q = n % 60;
    debug(p, q)
    int a1 = a, b1 = b;
    a1 += ((b1 + q) / 60 + p) % 12;
    b1 += (q) % 60;
    debug(a1, b1)
    a1 %= 12;
    b1 %= 60;
    debug(a1, b1)
    string tempstr1;
    if(a1 / 10)
    {
        tempstr1 += '1';
        char s = a1 % 10 + '0';
        tempstr1 += s;
    } else
    {
        tempstr1 += '0';
        char s = a1 % 10 + '0';
        tempstr1 += s;
    }
    if(b1 / 10)
    {
        char s = (b1 / 10) + '0';
        tempstr1 += s;
        s = (b1 % 10) + '0';
        tempstr1 += s;
    } else
    {
        tempstr1 += '0';
        char s = (b1 % 10) + '0';
        tempstr1 += s;
    }
    debug(tempstr1)
    while(tempstr1 != init)
    {
        string check = tempstr1;
        reverseStr(check);
        if(check == tempstr1) ans++;
        a1 += ((b1 + q) / 60 + p) % 12;
        b1 += (q) % 60;
        a1 %= 12;
        b1 %= 60;
        tempstr1 = "";
        if(a1 / 10)
        {
            tempstr1 += '1';
            char s = a1 % 10 + '0';
            debug(s, (a1 % 10));
            tempstr1 += s;
        } else
        {
            tempstr1 += '0';
            char s = a1 % 10 + '0';
            tempstr1 += s;
        }
        if(b1 / 10)
        {
            char s = (b1 / 10) + '0';
            tempstr1 += s;
            debug(s, b1, b1 / 10)
                s = (b1 % 10) + '0';
            debug(s)
                tempstr1 += s;
        } else
        {
            tempstr1 += '0';
            char s = (b1 % 10) + '0';
            debug(s)
                tempstr1 += s;
        }
        debug(tempstr1);
    }
    cout << ans;
    
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

