// ACCEPTED!

class SegTree {
private:
    int n;
    vector<int> tree;

public:
    SegTree (int size)
    {
        n = size;
        tree.resize(4*n, 3);
    }

    void printTree ()
    {
        for (int i = 0; i < 4*n; i++)
        {
            cout << tree[i] << ' ';
        }
        cout << '\n';
    }

    void update (int i, int x)
    {
        update(i, x, 0, n-1, 1);
    }

    void update (int i, int x, int l, int r, int nd)
    {
        if (l == r)
        {
            tree[nd] = x;
            return;
        }

        int mid = (l+r)/2;

        if (i <= mid)
            update(i, x, l, mid, 2*nd);
        else
            update(i, x, mid+1, r, 2*nd+1);

        tree[nd] = max(tree[2*nd], tree[2*nd+1]);
        return;
    }

    int query (int x)
    {
        if (tree[1] < x)
            return -1;

        return query(x, 0, n-1, 1);
    }

    int query (int x, int l, int r, int nd)
    {
        if (l == r)
            return l;

        int mid = (l+r)/2;

        if (tree[2*nd] >= x)
            return query(x, l, mid, 2*nd);
        else
            return query(x, mid+1, r, 2*nd+1);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets)
    {
        int n = fruits.size();

        SegTree st(n);

        for (int i = 0; i < n; i++)
        {
            st.update(i, baskets[i]);
        }

        int answer = 0;
        for (int f : fruits)
        {
            int idx = st.query(f);
            if (idx == -1)
                answer++;
            else
                st.update(idx, 0);
        }

        return answer;
    }
};
