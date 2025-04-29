/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 28-04-2025 17:23:27
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
int I = 0, Test = 1;

// balanced because of random priorities
class Treap {
    struct TreapNode {
        int value, priority, toProp;
        bool toFlip;
        pair<TreapNode *, TreapNode *> children;
        int subTreeSize;
        int sum;  // computed value

        void reCalc() {
            sum = value + toProp * subTreeSize;
            subTreeSize = 1;
            auto &[l, r] = children;
            if (l) {
                sum += l->sum + toProp * l->subTreeSize;
                subTreeSize += l->subTreeSize;
            }
            if (r) {
                sum += r->sum + toProp * r->subTreeSize;
                subTreeSize += r->subTreeSize;
            }
        }

        void lazyPropagate() {
            auto &[l, r] = children;

            if (l) {
                l->toProp += toProp;
                l->toFlip += toFlip;
            }
            if (r) {
                r->toProp += toProp;
                r->toFlip += toFlip;
            }
            if (toProp) {
                value += toProp;
                toProp = 0;
            }

            if (toFlip) {
                children = {r, l};
                toFlip = 0;
            }
        }

        TreapNode(int data) {
            value = data;
            toProp = 0;
            toFlip = false;
            children = {nullptr, nullptr};
            priority = (rand() << 16) ^ rand();
            reCalc();
        };
    };

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

    pair<TreapNode *, TreapNode *> split(TreapNode *root, int leftSegSize) {
        if (!root) {
            return {nullptr, nullptr};
        }
        root->lazyPropagate();
        TreapNode *l = root->children.first;
        TreapNode *r = root->children.second;
        int lSize = l ? l->subTreeSize : 0;
        if (lSize >= leftSegSize) {
            auto [lSegHead, rSegHead] = split(l, leftSegSize);
            root->children.first = rSegHead;
            root->reCalc();
            return {lSegHead, root};
        } else {
            auto [lSegHead, rSegHead] = split(r, leftSegSize - lSize - 1);
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

    void printTreap(TreapNode *root) {
        if (!root) {
            return;
        }
        printTreap(root->children.first);
        cout << root->value << " ";
        printTreap(root->children.second);
    }

   public:
    ~Treap() { freeTreap(root); }

    void insert(int x) {
        TreapNode *newNode = new TreapNode(x);
        root = merge(root, newNode);
    }

    void insertAt(int x, int index) {
        TreapNode *newNode = new TreapNode(x);
        auto [l, r] = split(root, index);
        TreapNode *updatedSegment = merge(l, newNode);
        root = merge(updatedSegment, r);
    }

    void erase(int index) {  // 0 based index input
        auto [l, r] = split(root, index + 1);
        TreapNode *toDelete = nullptr;
        auto [l1, r1] = split(l, index);
        toDelete = r1;
        root = merge(l1, r);
        freeTreap(toDelete);
    }

    void printTreap() {
        printTreap(root);
        cout << endl;
    }

    void flipRange(int l, int r) {  // 0 based index input
        int _1stSection = l, _2ndSection = r - l + 1;
        auto [_1st, _2ndMain] = split(root, _1stSection);
        auto [_2nd, _3rd] = split(_2ndMain, _2ndSection);
        _2nd->toFlip = true;
        root = merge(_1st, _2nd);
        root = merge(root, _3rd);
    }

    void rangeAdd(int l, int r, int toAdd) {  // 0 based index input
        int _1stSection = l, _2ndSection = r - l + 1;
        auto [_1st, _2ndMain] = split(root, _1stSection);
        auto [_2nd, _3rd] = split(_2ndMain, _2ndSection);
        _2nd->toProp += toAdd;
        root = merge(_1st, _2nd);
        root = merge(root, _3rd);
    }

    int rangedQuery(int l, int r) {  // 0 based index input
        int _1stSection = l, _2ndSection = r - l + 1;
        auto [_1st, _2ndMain] = split(root, _1stSection);
        auto [_2nd, _3rd] = split(_2ndMain, _2ndSection);
        int res = _2nd->sum;
        root = merge(_1st, _2nd);
        root = merge(root, _3rd);
        return res;
    }
};

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, maxEle = 0;
    cin >> n;
    Treap treap;
    for (int i = 0; i < n; i++) {
        char x;
        int y, r, num;
        cin >> x >> y;
        if (x == 'a') {
            treap.insert(y);
            treap.printTreap();
        }
        if (x == 'i') {
            cin >> r;
            treap.insertAt(y, r);
            treap.printTreap();
        }
        if (x == 'e') {
            treap.erase(y);
            treap.printTreap();
        }
        if (x == 'r') {
            cin >> r >> num;
            treap.rangeAdd(y, r, num);
            treap.printTreap();
        }
        if (x == 'q') {
            cin >> r;
            cout << treap.rangedQuery(y, r) << endl;
        }
        if (x == 'f') {
            cin >> r;
            treap.flipRange(y, r);
            treap.printTreap();
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
        cout << endl;
    }
}
