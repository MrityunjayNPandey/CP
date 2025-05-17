/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 16-05-2025 15:17:48
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
#define free                            \
    freopen("input.txt", "r", stdin);   \
    freopen("output.txt", "w", stdout); \
    freopen("error.txt", "w", stderr);
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long INF = INT_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
#define int long long
int I = 0, Test = 1;

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    string str;
    cin >> str;
    set<int> alice, bob;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'A') {
            alice.insert(i + 1);
        } else {
            bob.insert(i + 1);
        }
    }
    while (alice.size() && bob.size()) {
        debug(alice, bob);
        int aliceMin = *alice.begin();
        int bobMin = *bob.begin();
        int aliceMax = *(prev(alice.end()));
        int alice2ndMax = *(prev(prev(alice.end())));

        int bobMax = *bob.rbegin();

        if (aliceMax == n) {
            if (bobMin == 1) {
                if (alice.size() >= 2 && alice2ndMax > bobMax) {
                    bob.erase(bobMax);
                    alice.insert(bobMax);
                } else {
                    bob.insert(aliceMax);
                    alice.erase(aliceMax);
                }
                continue;
            }
        }

        if (aliceMin == 1) {
            if (bobMin == n) {
                bob.erase(bobMax);
                alice.insert(bobMax);
                continue;
            }
        }

        if (bobMin == 1) {
            if (aliceMin == n) {
                alice.erase(aliceMax);
                bob.insert(aliceMax);
                continue;
            }
        }

        if (aliceMax > bobMax) {
            bob.erase(bobMax);
            alice.insert(bobMax);
        } else {
            alice.erase(aliceMax);
            bob.insert(aliceMax);
        }
    }
    debug(alice, bob);
    if (bob.size()) {
        cout << "Bob";
    } else {
        cout << "Alice";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef SUBLIME
    free
#endif
            cin >>
        Test;
    for (I = 1; I <= Test; I++) {
        dclear(I);
        solve();
        cout << endl;
    }
}
