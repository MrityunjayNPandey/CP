/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 29-04-2025 17:33:37
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
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
#define int long long
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int I = 0, Test = 1;

class Treap {
    struct TreapNode {
        int value, priority, toProp, origVal, shirtsToProp;
        pair<TreapNode *, TreapNode *> children;
        int subTreeSize;
        int shirts;
        int index;

        void reCalc() {
            subTreeSize = 1;
            auto &[l, r] = children;
            if (l) {
                subTreeSize += l->subTreeSize;
            }
            if (r) {
                subTreeSize += r->subTreeSize;
            }
        }

        void lazyPropagate() {
            auto &[l, r] = children;

            if (l) {
                l->toProp += toProp;
                l->shirtsToProp += shirtsToProp;
            }
            if (r) {
                r->toProp += toProp;
                r->shirtsToProp += shirtsToProp;
            }

            value += toProp;
            shirts += shirtsToProp;
            toProp = 0;
            shirtsToProp = 0;
        }

        TreapNode(int data, int idx) {
            origVal = value = data;
            toProp = 0;
            shirts = 0;
            shirtsToProp = 0;
            index = idx;
            subTreeSize = 1;
            children = {nullptr, nullptr};
            priority = rng();
            reCalc();
        };
    };

    void freeTreap(TreapNode *root) {
        if (!root) return;
        freeTreap(root->children.first);
        freeTreap(root->children.second);
        delete root;
    }

    TreapNode *root = nullptr;

    void inorderTraversal(TreapNode *root, auto &v) {
        if (!root) {
            return;
        }
        root->lazyPropagate();
        inorderTraversal(root->children.first, v);
        v.push_back(root);
        inorderTraversal(root->children.second, v);
    }

    TreapNode *merge(TreapNode *p1, TreapNode *p2) {
        if (!p1 || !p2) {
            return p1 ? p1 : p2;
        }
        p1->lazyPropagate();
        p2->lazyPropagate();
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

    // <x and <=x
    pair<TreapNode *, TreapNode *> split(TreapNode *root, int leftTreeSize) {
        if (!root) {
            return {nullptr, nullptr};
        }
        root->lazyPropagate();
        TreapNode *l = root->children.first;
        TreapNode *r = root->children.second;
        int lSize = l ? l->subTreeSize : 0;
        if (lSize + 1 <= leftTreeSize) {
            auto [lSegHead, rSegHead] = split(r, leftTreeSize - lSize - 1);
            root->children.second = lSegHead;
            root->reCalc();
            return {root, rSegHead};
        } else {
            auto [lSegHead, rSegHead] = split(l, leftTreeSize);
            root->children.first = rSegHead;
            root->reCalc();
            return {lSegHead, root};
        }
    }

    pair<TreapNode *, TreapNode *> splitByValue(TreapNode *root, int k) {
        if (!root) {
            return {nullptr, nullptr};
        }
        root->lazyPropagate();
        TreapNode *l = root->children.first;
        TreapNode *r = root->children.second;
        if (root->value <= k) {
            auto [lSegHead, rSegHead] = splitByValue(r, k);
            root->children.second = lSegHead;
            root->reCalc();
            return {root, rSegHead};
        } else {
            auto [lSegHead, rSegHead] = splitByValue(l, k);
            root->children.first = rSegHead;
            root->reCalc();
            return {lSegHead, root};
        }
    }

    void insertByValue(TreapNode *&node, int x, int index) {
        TreapNode *newNode = new TreapNode(x, index);
        // SplitByValue the tree into <=x and >x
        auto [l, r] = splitByValue(node, x - 1);
        node = merge(merge(l, newNode), r);
    }

    void insertByNode(TreapNode *&node, TreapNode *newNode) {
        // SplitByValue the tree into <=x and >x
        auto [l, r] = splitByValue(node, newNode->value - 1);
        node = merge(merge(l, newNode), r);
    }

    TreapNode *orderedMerge(TreapNode *p1, TreapNode *p2) {
        if (!p1 || !p2) {
            return p1 ? p1 : p2;
        }
        p1->lazyPropagate();
        p2->lazyPropagate();
        auto &[l, r] = p2->children;

        if (l) {
            p1 = orderedMerge(p1, l);
        }
        if (r) {
            p1 = orderedMerge(p1, r);
        }

        p2->children = {nullptr, nullptr};
        insertByNode(p1, p2);
        return p1;
    }

   public:
    ~Treap() { freeTreap(root); }

    void insert(int x, int index) { insertByValue(root, x, index); }

    void erase(int index) {  // 0 based index input
        auto [l, r] = split(root, index + 1);
        TreapNode *toDelete = nullptr;
        auto [l1, r1] = split(l, index);
        toDelete = r1;
        root = merge(l1, r);
        freeTreap(toDelete);
    }

    vector<TreapNode *> getTreapVector() {
        vector<TreapNode *> vTreap;
        inorderTraversal(root, vTreap);
        return vTreap;
    }

    void doOperation(int x, TreapNode *&node) {
        if (!node) {
            return;
        }

        auto [l, r] = splitByValue(node, x - 1);

        if (r) {
            r->toProp -= x;
            r->shirtsToProp++;
        }

        auto [l1, r1] = splitByValue(r, x - 1);

        TreapNode *leftSegment = orderedMerge(l, l1);
        node = merge(leftSegment, r1);
    }

    void doOperation(int x) { doOperation(x, root); }
};

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
    auto &[l1, r1] = p1;
    auto &[l2, r2] = p2;
    if (r1 > r2) {
        return true;
    } else if (r1 < r2) {
        return false;
    } else {
        if (l1 > l2) {
            return false;
        } else {
            return true;
        }
    }
}

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<pair<int, int>> vp(n);
    Treap treap;
    for (auto &[l, r] : vp) {
        cin >> l >> r;
    }
    cin >> k;
    vector<pair<int, int>> vpB(k);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        vpB[i] = {x, i};
    }

    sort(vpB.begin(), vpB.end());
    for (auto &[l, r] : vpB) {
        treap.insert(l, r);
    }

    sort(vp.begin(), vp.end(), cmp);
    for (auto &[l, r] : vp) {
        treap.doOperation(l);
    }

    vector<int> vAns(k);

    for (auto &i : treap.getTreapVector()) {
        vAns[i->index] = i->shirts;
    }

    for (auto &i : vAns) {
        cout << i << " ";
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
        cout << endl;
    }
}
