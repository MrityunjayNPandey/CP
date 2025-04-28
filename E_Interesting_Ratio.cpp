/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 27-04-2025 02:09:51
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
const long long MAX_N = 1e7 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long INF = INT_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
#define int long long
int I = 0, Test = 1;
ordered_multiset mPrime;

// Sieve of Eratosthenes, time complexity of O(N*log(logN))
vector<int> primeTemp(MAX_N + 1, 1), isPrime(MAX_N + 1, 0), prime;
void SIEVE() {
    for (int p = 2; p <= MAX_N; p++) {
        if (primeTemp[p] == 1) {
            prime.push_back(p);
            mPrime.insert(p);
            isPrime[p]++;
            for (int i = p * p; i <= MAX_N; i += p) {
                primeTemp[i] = 0;
            }
        }
    }
}

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    set<pair<int, int>> st;
    int pSz = prime.size();
    for (int i = 1; i <= n; i++) {
        int l = 0, r = pSz - 1;
        int ind = -1;
        while (l <= r) {
            int mid = (r + l) / 2;
            if (prime[mid] > n / i) {
                r = mid - 1;
            } else {
                l = mid + 1;
                ind = mid;
            }
        }
        ans += ind + 1;
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef SUBLIME
    free
#endif
    SIEVE();
    cin >> Test;
    for (I = 1; I <= Test; I++) {
        dclear(I);
        solve();
        cout << endl;
    }
}
