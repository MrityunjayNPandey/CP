/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 25-07-2022 22:56:08
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
// #define int long long

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    // //here i do my code................................................................
    // after tgat i submit using ctrl+Alt+F

    // I use a extension for generating templates automatically when I parse a problem. 
    // ummmm wait a sec..............
    // sorry I'm not remembering that extension right now.........
    // I'll tell you if i remember it...
    // yes, I use this debug file, when I want to know what is the value of a variable or a vector.......
    // I'll show you
    //I'll send it to you
    //say I declare a vector of size n......
    n = 5;
    vector<int> v(n);
    //and it change the 3td element to 5
    v[2] = 5;
    //now If I want to see the vector, I'll just....
    debug(v)
    // int inr=1000000*1000000;
    //as you can see, I can see the vector in a different place......
    // like, standard error, and i dont need to comment it out
    // this works for all containers, but not in arrays......
    //you'll have to manually print it out or simply do this debug(arr[5])........

    //are you able to hear me???
    //Am I audible?.... ok

    // to use this file, you'll need to declare compiler flags...
    // the pic that i sent you was the compiler flags that I use..
    //they generally show me where the segmentation fault has occurred
    //its the same for linux
    //let me show you how...

        int x = v[-1];

    // int *p;
    // cout << *p << endl;
    // int x=0;
    // int y=10/x;
    // cout<<y;


    //this is just weird and an arror should occur.... right???
    //See, an error was generated, but on submitting the file on codeforces, it should give me runtime error??
    //right??
    //as you can see, CF didn't show the error 
    //No
    //You can get the exact line of where this error has occured on leetcode playground...., they have a really powerfull 
    //compiler
    //As you can see, leetcode is showing me the line number also... 
    //Now, have you precompiled your bits/stdc++.h file?????

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

