/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 22-03-2022 21:05:14
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

int LongestPalindromicPrefix(string str)
{

    // Create temporary string
    string temp = str + '?';

    // Reverse the string str
    reverse(str.begin(), str.end());

    // Append string str to temp
    temp += str;

    // Find the length of string temp
    int n = temp.length();

    // lps[] array for string temp
    int lps[n];

    // Initialise every value with zero
    fill(lps, lps + n, 0);

    // Iterate the string temp
    for(int i = 1; i < n; i++)
    {

// Length of longest prefix
// till less than i
        int len = lps[i - 1];

        // Calculate length for i+1
        while(len > 0
               && temp[len] != temp[i])
        {
            len = lps[len - 1];
        }

        // If character at current index
        // len are same then increment
        // length by 1
        if(temp[i] == temp[len])
        {
            len++;
        }

        // Update the length at current
        // index to len
        lps[i] = len;
    }

    // Print the palindromic string of
    // max_len
    return temp.substr(0, lps[n - 1]).length();
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    string s;
    cin >> s;
    string p = s;
    debug(p)
        LongestPalindromicPrefix(p);
    for(int i = 0; i < p.length(); i++)
    {
        if(p[i] == '(') sum++;
        else sum--;
        if(sum == 0)
        {
            ans = i + 1;
            break;
        }
    }
    m = LongestPalindromicPrefix(p);
    while(m > 1 || ans > 1)
    {
        debug(m, ans, p)
            m = 0;
        ans = 0;
        if(p.length() == 0)
            break;
        for(int i = 0; i < p.length(); i++)
        {
            if(p[i] == '(') sum++;
            else sum--;
            if(sum == 0)
            {
                ans = i + 1;
                break;
            }
        }
        m = LongestPalindromicPrefix(p);
        if(m <= ans)
            p = p.substr(m);
        else
            p = p.substr(ans);
        cnt++;
    }
    cout << cnt << " " << p.length();
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

