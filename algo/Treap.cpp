/**
 *  balanced because of random priorities
 *  merging and splitting is based on the number of nodes. Change it to value to get BST (don't touch the merge
 * function. Do change in split and insert)
 *  */
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

    pair<TreapNode *, TreapNode *> split(TreapNode *root, int leftTreeSize) {
        if (!root) {
            return {nullptr, nullptr};
        }
        root->lazyPropagate();
        TreapNode *l = root->children.first;
        TreapNode *r = root->children.second;
        int lSize = l ? l->subTreeSize : 0;
        if (lSize >= leftTreeSize) {
            auto [lSegHead, rSegHead] = split(l, leftTreeSize);
            root->children.first = rSegHead;
            root->reCalc();
            return {lSegHead, root};
        } else {
            auto [lSegHead, rSegHead] = split(r, leftTreeSize - lSize - 1);
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