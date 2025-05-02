/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 30-04-2025 21:25:01
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
#define free                                           \
    freopen("/workspaces/CP/input.txt", "r", stdin);   \
    freopen("/workspaces/CP/output.txt", "w", stdout); \
    freopen("/workspaces/CP/error.txt", "w", stderr);
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long INF = INT_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
#define int long long
int I = 0, Test = 1, t1p = 0;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/**
 *  balanced because of random priorities
 *  */
class Treap {
    struct TreapNode {
        int value, priority, toPropXOR, toPropFlip, toPropMakeOne, toPropMakeZero;
        pair<TreapNode *, TreapNode *> children;
        int subTreeSize;
        vector<int> mx, pref, suff, nums;

        void doFlip() { toPropFlip ^= true; }

        void rangeSetZero() {
            toPropXOR = false;
            toPropFlip = false;
            toPropMakeZero = true;
            toPropMakeOne = false;
        }

        void rangeSetOne() {
            toPropXOR = false;
            toPropFlip = false;
            toPropMakeZero = false;
            toPropMakeOne = true;
        }

        void doXor() {
            if (toPropMakeOne || toPropMakeZero) {
                if (toPropMakeZero)
                    rangeSetOne();
                else
                    rangeSetZero();
            } else {
                toPropXOR ^= true;
            }
        }

        void reCalc() {
            if (toPropXOR || toPropFlip || toPropMakeOne || toPropMakeZero) {
                debug("FUCKUP");
            }
            auto &[l, r] = children;
            int lMx[2] = {0}, lPref[2] = {0}, lSuff[2] = {0}, lNums[2] = {0};
            int rMx[2] = {0}, rPref[2] = {0}, rSuff[2] = {0}, rNums[2] = {0};
            subTreeSize = 1;
            int lSz = 0, rSz = 0;

            if (l) {
                lSz = l->subTreeSize;
                subTreeSize += lSz;
                for (int i = 0; i < 2; i++) {
                    lMx[i] = l->mx[i];
                    lPref[i] = l->pref[i];
                    lSuff[i] = l->suff[i];
                    lNums[i] = l->nums[i];
                }

                if (l->toPropMakeOne) {
                    lMx[0] = lPref[0] = lSuff[0] = lNums[0] = 0;
                    lMx[1] = lPref[1] = lSuff[1] = lNums[1] = l->subTreeSize;
                }

                if (l->toPropMakeZero) {
                    lMx[1] = lPref[1] = lSuff[1] = lNums[1] = 0;
                    lMx[0] = lPref[0] = lSuff[0] = lNums[0] = l->subTreeSize;
                }

                if (l->toPropXOR) {
                    swap(lMx[0], lMx[1]);
                    swap(lPref[0], lPref[1]);
                    swap(lSuff[0], lSuff[1]);
                    swap(lNums[0], lNums[1]);
                }

                if (l->toPropFlip) {
                    swap(lPref, lSuff);
                }
            }
            if (r) {
                rSz = r->subTreeSize;
                subTreeSize += rSz;
                for (int i = 0; i < 2; i++) {
                    rMx[i] = r->mx[i];
                    rPref[i] = r->pref[i];
                    rSuff[i] = r->suff[i];
                    rNums[i] = r->nums[i];
                }

                if (r->toPropMakeOne) {
                    rMx[0] = rPref[0] = rSuff[0] = rNums[0] = 0;
                    rMx[1] = rPref[1] = rSuff[1] = rNums[1] = r->subTreeSize;
                }

                if (r->toPropMakeZero) {
                    rMx[1] = rPref[1] = rSuff[1] = rNums[1] = 0;
                    rMx[0] = rPref[0] = rSuff[0] = rNums[0] = r->subTreeSize;
                }

                if (r->toPropXOR) {
                    swap(rMx[0], rMx[1]);
                    swap(rPref[0], rPref[1]);
                    swap(rSuff[0], rSuff[1]);
                    swap(rNums[0], rNums[1]);
                }

                if (r->toPropFlip) {
                    swap(rPref, rSuff);
                }
            }

            pref[0] = lPref[0];
            pref[1] = lPref[1];
            suff[0] = rSuff[0];
            suff[1] = rSuff[1];
            nums[0] = lNums[0] + rNums[0];
            nums[1] = lNums[1] + rNums[1];
            nums[value] += 1;

            if (lPref[value] == lSz) {
                pref[value] += 1 + rPref[value];
            }
            if (rSuff[value] == rSz) {
                suff[value] += 1 + lSuff[value];
            }

            mx[0] = mx[1] = 0;
            mx[value] = lSuff[value] + 1 + rPref[value];
            mx[0] = max(mx[0], max(lMx[0], rMx[0]));
            mx[1] = max(mx[1], max(lMx[1], rMx[1]));
        }

        void lazyPropagate() {
            auto &[l, r] = children;

            if (toPropXOR & 1) {
                value ^= 1;
                if (l) {
                    l->doXor();
                }
                if (r) {
                    r->doXor();
                }
            }

            if (toPropMakeOne) {
                value = 1;
                if (l) {
                    l->rangeSetOne();
                }
                if (r) {
                    r->rangeSetOne();
                }
            }

            if (toPropFlip & 1) {
                swap(l, r);
                if (l) {
                    l->doFlip();
                }
                if (r) {
                    r->doFlip();
                }
            }

            if (toPropMakeZero) {
                value = 0;
                if (l) {
                    l->rangeSetZero();
                }
                if (r) {
                    r->rangeSetZero();
                }
            }

            toPropXOR = 0;
            toPropFlip = 0;
            toPropMakeOne = 0;
            toPropMakeZero = 0;
            reCalc();
        }

        TreapNode(int data) {
            value = data;
            toPropXOR = 0;
            toPropFlip = 0;
            toPropMakeOne = 0;
            toPropMakeZero = 0;
            children = {nullptr, nullptr};
            priority = rng();
            mx = vector<int>(2);
            pref = vector<int>(2);
            suff = vector<int>(2);
            nums = vector<int>(2);
            reCalc();
        };
    };

    TreapNode *root = nullptr;

    void freeTreap(TreapNode *root) {
        if (!root) return;
        freeTreap(root->children.first);
        freeTreap(root->children.second);
        delete root;
    }

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

    // <=leftTreeSize and <leftTreeSize
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

    // <=k and >k
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

    void insertByValue(TreapNode *&node, int x) {
        TreapNode *newNode = new TreapNode(x);
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

    void insert(int x) {
        TreapNode *newNode = new TreapNode(x);
        root = merge(root, newNode);
    }

    void orderedInsert(int x) { insertByValue(root, x); }

    void insertAt(int x, int index) {
        TreapNode *newNode = new TreapNode(x);
        auto [l, r] = split(root, index);
        TreapNode *updatedSegment = merge(l, newNode);
        root = merge(updatedSegment, r);
    }

    void eraseByIndex(int index) {  // 0 based index input
        auto [l, r] = split(root, index + 1);
        TreapNode *toDelete = nullptr;
        auto [l1, r1] = split(l, index);
        toDelete = r1;
        root = merge(l1, r);
        freeTreap(toDelete);
    }

    void eraseByValue(int k) {  // 0 based index input
        auto [l, r] = splitByValue(root, k);
        TreapNode *toDelete = nullptr;
        auto [l1, r1] = splitByValue(l, k - 1);
        toDelete = r1;
        root = merge(l1, r);
        freeTreap(toDelete);
    }

    vector<TreapNode *> getTreapVector() {
        vector<TreapNode *> vTreap;
        inorderTraversal(root, vTreap);
        return vTreap;
    }

    void debugTreap() {
#ifdef DEBUG
        auto treap = getTreapVector();
        for (auto &i : treap) {
            clog << i->value << " ";
            // debug(i->value, i->pref, i->suff, i->mx);
        }
        // clog << endl;
#endif
    }

    void rangeXOR(int l, int r) {  // 0 based index input
        int _1stSection = l, _2ndSection = r - l + 1;
        auto [_1st, _2ndMain] = split(root, _1stSection);
        auto [_2nd, _3rd] = split(_2ndMain, _2ndSection);
        _2nd->doXor();
        root = merge(_1st, merge(_2nd, _3rd));
    }

    void flipRange(int l, int r) {  // 0 based index input
        int _1stSection = l, _2ndSection = r - l + 1;
        auto [_1st, _2ndMain] = split(root, _1stSection);
        auto [_2nd, _3rd] = split(_2ndMain, _2ndSection);
        _2nd->doFlip();
        root = merge(_1st, _2nd);
        root = merge(root, _3rd);
    }

    void sortRange(int l, int r) {  // 0 based index input
        int _1stSection = l, _2ndSection = r - l + 1;
        auto [_1st, _2ndMain] = split(root, _1stSection);
        auto [_2nd, _3rd] = split(_2ndMain, _2ndSection);

        int num0 = _2nd->nums[0];
        auto [_2nd1, _2nd2] = split(_2nd, num0);
        if (_2nd1) {
            _2nd1->rangeSetZero();
        }
        if (_2nd2) {
            _2nd2->rangeSetOne();
        }
        _2nd = merge(_2nd1, _2nd2);

        root = merge(_1st, _2nd);
        root = merge(root, _3rd);
    }

    int getMax() { return max(root->mx[0], root->mx[1]); }
};

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    string str;
    cin >> str;
    Treap treap;
    for (auto &i : str) {
        treap.insert(i - '0');
    }
    // treap.debugTreap();
    while (k--) {
        cnt++;
        int x, l, r;
        cin >> x >> l >> r;
        if (x == 1) {
            treap.rangeXOR(l - 1, r - 1);
        } else if (x == 2) {
            treap.flipRange(l - 1, r - 1);
        } else {
            // treap.debugTreap();
            treap.sortRange(l - 1, r - 1);
        }
        cout << treap.getMax() << endl;
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
