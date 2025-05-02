/**
 *      codeforces: _joKer_0
 *      leetcode:  joKer0
 *      created: 30-04-2025 15:28:16
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

// IDK about this string hashing algo, just used
class HarmeyerHash {
    static const int s1 = 257;  // Make hash parameters static const
    static const int s2 = 619;
    static vector<int> s1Pow, s2Pow;
    static bool precomped;

    int v1 = 0, v2 = 0;
    int length = 0;

   public:
    HarmeyerHash() : v1(0), v2(0), length(0) {}  // Remove precomped assignment from constructor

    void add(char c) {
        v1 = (v1 * s1 + c) % mod;
        v2 = (v2 * s2 + c) % MOD;
        length++;
    }

    bool operator<(const HarmeyerHash &o) const {
        if (v1 != o.v1) return v1 < o.v1;
        return v2 < o.v2;
    }

    bool operator==(const HarmeyerHash &o) const { return v1 == o.v1 && v2 == o.v2; }

    HarmeyerHash clone() const {
        HarmeyerHash copy;
        copy.v1 = v1;
        copy.v2 = v2;
        copy.length = length;
        return copy;
    }

    static void precomp() {
        if (precomped) return;
        debug("precomp running");
        precomped = true;
        s1Pow.resize(1000000);
        s2Pow.resize(1000000);
        s1Pow[0] = s2Pow[0] = 1;
        for (int i = 1; i < s1Pow.size(); i++) {
            s1Pow[i] = (s1Pow[i - 1] * s1) % mod;
            s2Pow[i] = (s2Pow[i - 1] * s2) % MOD;
        }
    }

    // need fastPow if other hash can be longer than 10^6
    void append(const HarmeyerHash &other) {
        precomp();
        v1 = (v1 * s1Pow[other.length] + other.v1) % mod;
        v2 = (v2 * s2Pow[other.length] + other.v2) % MOD;
        length += other.length;
    }

    vector<HarmeyerHash> getPrefixHashes(const string &word) {
        precomp();
        vector<HarmeyerHash> hashes(word.length() + 1);
        for (int i = 1; i <= word.length(); i++) {
            hashes[i] = hashes[i - 1].clone();
            hashes[i].add(word[i - 1]);
        }
        return hashes;
    }

    // [from, to)
    HarmeyerHash substringHash(const vector<HarmeyerHash> &prefixHashes, int from, int to) {
        if (from == to) return HarmeyerHash();
        HarmeyerHash result = prefixHashes[to].clone();
        HarmeyerHash toSub = prefixHashes[from];
        int diff = to - from;
        result.v1 = (result.v1 - (toSub.v1 * s1Pow[diff]) % mod + mod) % mod;
        result.v2 = (result.v2 - (toSub.v2 * s2Pow[diff]) % MOD + MOD) % MOD;
        result.length = to - from;
        return result;
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/**
 *  balanced because of random priorities
 *  */
class Treap {
    struct TreapNode {
        int priority, toProp;
        bool toFlip;
        pair<TreapNode *, TreapNode *> children;
        int subTreeSize;
        char value;
        HarmeyerHash *rangeHash;

        void reCalc() {
            subTreeSize = 1;
            // Delete and create new rangeHash
            if (rangeHash) {
                delete rangeHash;
            }
            rangeHash = new HarmeyerHash();

            auto &[l, r] = children;
            // Append left child's hash
            if (l) {
                subTreeSize += l->subTreeSize;
                rangeHash->append(*(l->rangeHash));
            }
            // Add current node's value
            rangeHash->add(value);
            // Append right child's hash
            if (r) {
                subTreeSize += r->subTreeSize;
                rangeHash->append(*(r->rangeHash));
            }
        }

        TreapNode(char data) {
            value = data;
            toProp = 0;
            toFlip = false;
            children = {nullptr, nullptr};
            rangeHash = nullptr;
            priority = rng();
            reCalc();
        };

        ~TreapNode() {
            delete rangeHash;  // Clean up rangeHash
        }
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
        inorderTraversal(root->children.first, v);
        v.push_back(root);
        inorderTraversal(root->children.second, v);
    }

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

    // <= and >
    pair<TreapNode *, TreapNode *> split(TreapNode *root, int leftTreeSize) {
        if (!root) {
            return {nullptr, nullptr};
        }
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

   public:
    ~Treap() { freeTreap(root); }

    void insert(char x) {
        TreapNode *newNode = new TreapNode(x);
        root = merge(root, newNode);
    }

    void insertAt(char x, int index) {
        TreapNode *newNode = new TreapNode(x);
        auto [l, r] = split(root, index);
        TreapNode *updatedSegment = merge(l, newNode);
        root = merge(updatedSegment, r);
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
        }
        clog << endl;
#endif
    }

    void removeSubString(int lInd, int rInd) {
        auto [l, r] = split(root, lInd);
        auto [l1, r1] = split(r, rInd - lInd + 1);
        root = merge(l, r1);
        freeTreap(l1);
    }

    void removeSubStringReversed(int lInd, int rInd) {
        removeSubString(root->subTreeSize - rInd - 1, root->subTreeSize - lInd - 1);
    }
    void insertAtReversed(char p, int ind) { insertAt(p, root->subTreeSize - ind); }

    HarmeyerHash getHashOfRange(int lInd, int rInd) {
        auto [l, r] = split(root, lInd);
        auto [l1, r1] = split(r, rInd - lInd + 1);
        HarmeyerHash res = l1->rangeHash->clone();
        root = merge(l, merge(l1, r1));
        return res;
    }

    HarmeyerHash getHashOfRangeReversed(int lInd, int rInd) {
        return getHashOfRange(root->subTreeSize - rInd - 1, root->subTreeSize - lInd - 1);
    }
};

// Outside the class
vector<long long> HarmeyerHash::s1Pow;
vector<long long> HarmeyerHash::s2Pow;
bool HarmeyerHash::precomped = false;

void solve() {
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    string str;
    cin >> str;
    Treap treap;
    Treap revTreap;
    for (auto &i : str) {
        treap.insert(i);
        revTreap.insertAt(i, 0);
    }
    treap.debugTreap();
    revTreap.debugTreap();
    while (k--) {
        int x;
        cin >> x;
        int l, r;
        if (x == 1) {
            cin >> l >> r;
            treap.removeSubString(l - 1, r - 1);
            revTreap.removeSubStringReversed(l - 1, r - 1);
            debug(x, "---------");
            treap.debugTreap();
            revTreap.debugTreap();
            debug("---------");
        } else if (x == 2) {
            char p;
            int ind;
            cin >> p >> ind;
            treap.insertAt(p, ind - 1);
            revTreap.insertAtReversed(p, ind - 1);
            debug(x, "---------");
            treap.debugTreap();
            revTreap.debugTreap();
            debug("---------");
        } else {
            cin >> l >> r;
            auto h1 = treap.getHashOfRange(l - 1, r - 1);
            auto h2 = revTreap.getHashOfRangeReversed(l - 1, r - 1);
            if (h1 == h2) {
                cout << "yes";
            } else {
                cout << "no";
            }
            cout << endl;
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
