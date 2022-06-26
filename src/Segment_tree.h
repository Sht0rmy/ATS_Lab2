#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <cmath>
#include <vector>

using namespace std;

template <typename T>
class SegmentTree
{
public:
    int n;
    vector<T> t;

    SegmentTree(vector<T> &a)
    {
        n = a.size();
        t.resize(n * 4);
        build(a, 1, 0, n - 1);
    }

    void build(vector<T> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            t[v] = a[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    T sum(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return {0, 0};
        if (l == tl && r == tr)
        {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int v, int tl, int tr, int pos, T new_val)
    {
        if (tl == tr)
        {
            t[v] = new_val;
        }
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
};

#endif
