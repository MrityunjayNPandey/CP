/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 25-02-2025 06:00:16
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
    cin >> n;
    vector<int> v(n, -1);
    vector<string> adjList(n);
    set<int> available;
    for (auto &i : adjList) {
        available.insert(k++);
        cin >> i;
    }
    for (int i = n - 1; i >= 0; i--) {
        int left = 0, right = 0;
        for (int j = 0; j < adjList[i].length(); j++) {
            if (adjList[i][j] == '1') {
                if (j < i) {
                    left++;
                }
            }
        }
        debug(left);
        k = 0;
        int val = -1;
        for (auto &i : available) {
            if (left == k) {
                val = i;
                break;
            }
            k++;
        }
        v[val] = i + 1;
        available.erase(val);
    }
    for (auto &i : v) {
        cout << i << " ";
    }
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

void dfs(TreeNode *root, int low, int high, int currentSum) {
    if (root == NULL) {
        return;
    }

    int currentSum = currentSum + root->val;

    if (root->left == NULL && root->right == NULL) {
        if (currentSum >= low && currentSum <= high) {
            ans += currentSum;
        }
    } else if (root->left == NULL) {
        if (currentSum >= low && currentSum <= high) {
            ans += currentSum;
        }
    } else if (root->right == NULL) {
        if (currentSum >= low && currentSum <= high) {
            ans += currentSum;
        }
    }

    dfs(root->left, low, high, currentSum);
    dfs(root->right, low, high, currentSum);
}

int sumRootToLeafPaths(TreeNode *root, int low, int high) {
    ans = 0;
    dfs(root, low, high, 0);
    return ans;
}