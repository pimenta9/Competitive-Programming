#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> h;

struct SegTree
{
    int n;
    vector<int> tree;

    SegTree (int size)
    {
        n = size;
        tree.resize(4*n, 0);
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

    int query(int ql, int qr)
    {
        return query(ql, qr, 0, n-1, 1);
    }

    int query (int ql, int qr, int l, int r, int nd)
    {
        if (l > qr or r < ql)
            return 0;

        if (l >= ql and r <= qr)
            return tree[nd];

        int mid = (l+r)/2;

        int left = query(ql, qr, l, mid, 2*nd);
        int right = query(ql, qr, mid+1, r, 2*nd+1);

        return max(left, right);
    }
};

vector<int> right_wall()
{
    vector<int> ans(n);

    stack<pair<int, int>> s;

    for (int i = n-1; i >= 0; i--)
    {
        while (!s.empty() and s.top().first < h[i])
            s.pop();

        ans[i] = s.empty()? n : s.top().second;

        s.push({h[i], i});
    }

    return ans;
}

vector<int> left_wall()
{
    vector<int> ans(n);

    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() and s.top().first < h[i])
            s.pop();

        ans[i] = s.empty()? -1 : s.top().second;

        s.push({h[i], i});
    }

    return ans;
}

int main ()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    h.resize(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    // primeira parte: stack monotonica para descobrir as "paredes"
// que delimitam cada índice

    vector<int> left = left_wall();
    vector<int> right = right_wall();

    // segunda parte: DP usando SegTree para ver qual o próximo melhor
// caminho a ser tomado

    vector<pair<int, int>> h2;
    for (int i = 0; i < n; i++)
        h2.push_back({h[i], i});
    sort(h2.begin(), h2.end());

    SegTree st(n);

    for (auto [_, i] : h2)
    {
        st.update(i, 1 + st.query(left[i]+1, right[i]-1));
    }

    cout << st.tree[1] << '\n';

    return 0;
}
