#include <bits/stdc++.h>

constexpr int Maxn = 2e5 + 7;

struct Node
{
    int Max, Maxc, Maxr;
} seg[Maxn << 2];

long long val[Maxn], sum[Maxn];
int n, q;

void update(int p, int k)
{
    for (int i = p; i <= n; i += i & -i)
    {
        val[i] += k;
        sum[i] += 1LL * p * k;
    }
}

void update(int l, int r, int k)
{
    update(l, k), update(r + 1, -k);
}

long long query(int p)
{
    long long res = 0;

    for (int i = p; i > 0; i -= i & -i)
        res += 1LL * (p + 1) * val[i] - sum[i];

    return res;
}

inline void pushup(int p)
{
    seg[p].Maxr = -1;

    if (seg[p << 1].Max > seg[p << 1 | 1].Max)
    {
        seg[p].Max = seg[p << 1].Max;
        seg[p].Maxc = seg[p << 1].Maxc;
        seg[p].Maxr = seg[p << 1 | 1].Max;
    }
    else if (seg[p << 1].Max < seg[p << 1 | 1].Max)
    {
        seg[p].Max = seg[p << 1 | 1].Max;
        seg[p].Maxc = seg[p << 1 | 1].Maxc;
        seg[p].Maxr = seg[p << 1].Max;
    }
    else
    {
        seg[p].Max = seg[p << 1].Max;
        seg[p].Maxc = seg[p << 1].Maxc + seg[p << 1 | 1].Maxc;
    }

    seg[p].Maxr = std::max(seg[p].Maxr, std::max(seg[p << 1].Maxr, seg[p << 1 | 1].Maxr));
}

inline void pushdown(int p)
{
    if (seg[p].Max < seg[p << 1].Max)
        seg[p << 1].Max = seg[p].Max;
    if (seg[p].Max < seg[p << 1 | 1].Max)
        seg[p << 1 | 1].Max = seg[p].Max;
}

void update(int p, int l, int r, int x, int k)
{
    if (l == r)
    {
        update(1, seg[p].Max, -1);
        update(1, k, 1);
        seg[p].Max = k, seg[p].Maxc = 1, seg[p].Maxr = -1;
        return;
    }

    pushdown(p);
    int mid = (l + r) >> 1;

    if (x <= mid)
        update(p << 1, l, mid, x, k);
    else
        update(p << 1 | 1, mid + 1, r, x, k);

    pushup(p);
}

void update(int p, int l, int r, int L, int R, int k)
{
    if (k >= seg[p].Max)
        return;

    if (L <= l && r <= R && k > seg[p].Maxr)
    {
        update(k + 1, seg[p].Max, -seg[p].Maxc);
        seg[p].Max = k;
        return;
    }

    pushdown(p);
    int mid = (l + r) >> 1;

    if (L <= mid)
        update(p << 1, l, mid, L, R, k);
    if (R > mid)
        update(p << 1 | 1, mid + 1, r, L, R, k);

    pushup(p);
}

int main()
{
    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; ++i)
    {
        update(1, 1, n, i, i);
        update(1, i - 1, -1);
    }

    while (q--)
    {
        int opt, x, y;
        scanf("%d%d%d", &opt, &x, &y);

        if (opt == 1)
        {
            update(1, 1, n, x, y);

            if (x > 1)
                update(1, 1, n, 1, x - 1, x - 1);
        }
        else
            printf("%lld\n", query(y) - query(x - 1));
    }
}