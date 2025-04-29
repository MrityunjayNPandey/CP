/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 29-04-2025 14:59:22
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

/**
 *  balanced because of random priorities
 *  merging and splitting is based on the number of nodes. Change it to value to get BST
 *  */
class Treap {
    struct TreapNode {
        int value, priority;
        pair<TreapNode *, TreapNode *> children;
        int subTreeSize;
        int sum;  // computed value
        int mx, mn;

        void reCalc() {
            sum = mx = mn = value;
            subTreeSize = 1;
            auto &[l, r] = children;
            if (l) {
                sum += l->sum;
                mx = max(mx, l->mx);
                mn = min(mn, l->mn);
                subTreeSize += l->subTreeSize;
            }
            if (r) {
                sum += r->sum;
                mx = max(mx, r->mx);
                mn = min(mn, r->mn);
                subTreeSize += r->subTreeSize;
            }
        }

        TreapNode(int data) {
            value = data;
            children = {nullptr, nullptr};
            mx = INT_MIN;
            mn = INT_MAX;
            priority = (rand() << 16) ^ rand();
            reCalc();
        };
    };

    TreapNode *merge(TreapNode *p1, TreapNode *p2) {
        if (!p1 || !p2) {
            return p1 ? p1 : p2;
        }
        if (p1->priority < p2->priority) {
            p1->children.second = merge(p1->children.second, p2);
            p1->reCalc();
            return p1;
        } else {
            p2->children.first = merge(p1, p2->children.first);
            p2->reCalc();
            return p2;
        }
    }

    pair<TreapNode *, TreapNode *> split(TreapNode *root, int k) {
        if (!root) {
            return {nullptr, nullptr};
        }
        TreapNode *l = root->children.first;
        TreapNode *r = root->children.second;
        int lSize = l ? l->subTreeSize : 0;
        if (lSize >= k) {
            auto [lSegHead, rSegHead] = split(l, k);
            root->children.first = rSegHead;
            root->reCalc();
            return {lSegHead, root};
        } else {
            auto [lSegHead, rSegHead] = split(r, k - lSize - 1);
            root->children.second = lSegHead;
            root->reCalc();
            return {root, rSegHead};
        }
    }

    pair<TreapNode *, TreapNode *> splitByValue(TreapNode *root, int k) {
        if (!root) {
            return {nullptr, nullptr};
        }
        TreapNode *l = root->children.first;
        TreapNode *r = root->children.second;
        if (root->value >= k) {
            auto [lSegHead, rSegHead] = splitByValue(l, k);
            root->children.first = rSegHead;
            root->reCalc();
            return {lSegHead, root};
        } else {
            auto [lSegHead, rSegHead] = splitByValue(r, k);
            root->children.second = lSegHead;
            root->reCalc();
            return {root, rSegHead};
        }
    }

    void freeTreap(TreapNode *root) {
        if (!root) return;
        freeTreap(root->children.first);
        freeTreap(root->children.second);
        delete root;
    }

    TreapNode *root = nullptr;

    void inorderTraversal(TreapNode *root, vector<int> &v) {
        if (!root) {
            return;
        }
        inorderTraversal(root->children.first, v);
        v.push_back(root->value);
        inorderTraversal(root->children.second, v);
    }

   public:
    ~Treap() { freeTreap(root); }

    void insert(int x) {
        TreapNode *newNode = new TreapNode(x);
        // SplitByValue the tree into <=x and >x
        auto [l, r] = splitByValue(root, x);
        root = merge(merge(l, newNode), r);
    }

    void erase(int value) {  // based value input
        auto [l, r] = splitByValue(root, value + 1);
        TreapNode *toDelete = nullptr;
        auto [l1, r1] = splitByValue(l, value);
        toDelete = r1;
        root = merge(l1, r);
        freeTreap(toDelete);
    }

    void printTreap() {
        vector<int> v;
        inorderTraversal(root, v);
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    int getMaxDiffInRange(int l, int r) {  // 0 based index input
        int _1stSection = l, _2ndSection = r - l + 1;
        auto [_1st, _2ndMain] = split(root, _1stSection);
        auto [_2nd, _3rd] = split(_2ndMain, _2ndSection);
        int mx = _2nd->mx, mn = _2nd->mn;
        root = merge(_1st, _2nd);
        root = merge(root, _3rd);
        return mx - mn;
    }

    int getMinDiffInRange(int l, int r) {  // 0 based index input
        int _1stSection = l, _2ndSection = r - l + 1;
        auto [_1st, _2ndMain] = split(root, _1stSection);
        auto [_2nd, _3rd] = split(_2ndMain, _2ndSection);
        vector<int> v;
        inorderTraversal(_2nd, v);
        int mn = INT_MAX;
        for (int i = 1; i < v.size(); i++) {
            mn = min(mn, v[i] - v[i - 1]);
        }
        root = merge(_1st, _2nd);
        root = merge(root, _3rd);
        return mn;
    }
};

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    Treap treap;
    while (n--) {
        char x;
        cin >> x >> k;
        if (x == 'I') {
            treap.insert(k);
        } else if (x == 'D') {
            debug(k);
            treap.erase(k);
        } else {
            int r;
            cin >> r;
            if (x == 'X') {
                if (k == r) {
                    cout << -1;
                } else {
                    cout << treap.getMaxDiffInRange(k, r);
                }
                cout << endl;
            } else {
                if (k == r) {
                    cout << -1;
                } else {
                    cout << treap.getMinDiffInRange(k, r);
                }
                cout << endl;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef SUBLIME
    free
#endif
        for (I = 1; I <= Test; I++) {
        dclear(I);
        solve();
    }
}
