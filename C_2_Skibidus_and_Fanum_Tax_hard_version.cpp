/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 26-02-2025 04:15:06
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
#define free                                                                   \
    freopen("input.txt", "r", stdin);                                          \
    freopen("output.txt", "w", stdout);                                        \
    freopen("error.txt", "w", stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_map;
#define int long long

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &i : a) {
        cin >> i;
    }
    set<int> st;
    for (auto &i : b) {
        cin >> i;
        st.insert(i);
    }
    a[0] = min(a[0], *st.begin() - a[0]);
    for (int i = 1; i < n; i++) {
        auto it = st.lower_bound(a[i] + a[i - 1]);
        int newNumber = *it - a[i];
        if (a[i] >= a[i - 1]) {
            if (newNumber >= a[i - 1]) {
                a[i] = min(a[i], newNumber);
            }
        } else {
            if (newNumber >= a[i - 1]) {
                a[i] = newNumber;
            } else {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    cin >> Test;
    for (int I = 1; I <= Test; I++) {
        dclear(I);
        solve();
        cout << endl;
    }
}

int ans = 0;

int dfs(TreeNode *root, int low, int high, int currentSum) {
    if (root == NULL) {
        if (currentSum >= low && currentSum <= high) {
            ans += currentSum;
        }
        return;
    }
    dfs(root->left, low, high, currentSum + root->val);
    dfs(root->right, low, high, currentSum + root->val);
}

int sumRootToLeafPaths(TreeNode *root, int low, int high) {
    ans = 0;
    dfs(root, low, high, 0);
    return ans;
}