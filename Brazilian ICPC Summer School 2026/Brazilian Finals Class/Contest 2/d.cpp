#include <bits/stdc++.h>
using namespace std;

// defines
#define pii pair<int, int>
#define int long long
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define gauss(x) ((x*(x+1))/2)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int32_t(x.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define rep(i, a, b) for(int i = a; i < b; i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vi>

// consts
const int oo = 4e18;
const long double pi = acos(-1.0);
const int mod = (int) 1e9+7;
const int MAXN = 1e5;

// templates
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}
//

struct SegTree
{
    int n;
    vi tree, lazy;

    SegTree (int sz)
    {
        n = sz;
        tree.resize(4*n);
        lazy.resize(4*n);
    }

    void push (int l, int r, int nd)
    {
        if(lazy[nd] == 0)
            return;

        int mid = (l+r)/2;

        tree[2*nd] = mid-l+1;
        lazy[2*nd] = lazy[nd];

        tree[2*nd+1] = r-(mid+1)+1;
        lazy[2*nd+1] = lazy[nd];

        lazy[nd] = 0;
    }

    void fill (int ql, int qr)
    {
        fill(ql, qr, 0, n-1, 1);
    }

    void fill (int ql, int qr, int l, int r, int nd)
    {
        if(l > qr or r < ql)
            return;

        int size = r-l+1;
        if(l >= ql and r <= qr)
        {
            lazy[nd] = 1;
            tree[nd] = size;
            return;
        }

        push(l, r, nd);

        int mid = (l+r)/2;
        fill(ql, qr, l, mid, 2*nd);
        fill(ql, qr, mid+1, r, 2*nd+1);

        tree[nd] = tree[2*nd] + tree[2*nd+1];
    }

    void empty (int i)
    {
        empty(i, 0, n-1, 1);
    }

    void empty (int i, int l, int r, int nd)
    {
        if(l == r)
        {
            tree[nd] = 0;
            return;
        }

        push(l, r, nd);

        int mid = (l+r)/2;

        if(i <= mid)
            empty(i, l, mid, 2*nd);
        else
            empty(i, mid+1, r, 2*nd+1);

        tree[nd] = tree[2*nd] + tree[2*nd+1];
    }

    int sum (int ql, int qr)
    {
        return sum(ql, qr, 0, n-1, 1);
    }

    int sum (int ql, int qr, int l, int r, int nd)
    {
        if(l > qr or r < ql)
            return 0;

        if(l >= ql and r <= qr)
            return tree[nd];

        push(l, r, nd);

        int mid = (l+r)/2;

        int left = sum(ql, qr, l, mid, 2*nd);
        int right = sum(ql, qr, mid+1, r, 2*nd+1);

        return left + right;
    }
};

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    vvi adj(n);
    rep(i, 0, n-1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    int idx = 0;
    vi right_bound(n), aka(n), vis(n), parent(n);

    auto dfs = [&](auto rc, int u) -> int
    {
        vis[u] = true;
        aka[u] = idx++;

        int sub_tree_r = -1;
        for(int v : adj[u])
        {
            if(vis[v]) continue;

            parent[idx] = aka[u];
            sub_tree_r = max(sub_tree_r, rc(rc, v));
        }

        if(sub_tree_r == -1)
            return right_bound[aka[u]] = aka[u];
        return right_bound[aka[u]] = sub_tree_r;
    };

    right_bound[0] = dfs(dfs, 0);
    parent[0] = 0;
    // cout << parent << '\n';
    // cout << aka << '\n';
    // cout << right_bound << '\n';

    SegTree st(n);

    int q; cin >> q;
    // for(int i = 1; i <= 15; i++)
    //     cout << st.tree[i] << ' ';
    // cout << '\n';
    while(q--)
    {
        int op, v;
        cin >> op >> v;
        v--;
        v = aka[v];

        if(op == 1)
        {
            bool one_empty;
            if(v == 0 or st.sum(v, right_bound[v]) == right_bound[v]-v+1)
                one_empty = false;
            else
                one_empty = true;
            if(one_empty) st.empty(parent[v]);
            st.fill(v, right_bound[v]);
        }

        if(op == 2)
        {
            st.empty(v);
        }

        if(op == 3)
        {
            int sum = st.sum(v, right_bound[v]);
            if(sum == right_bound[v]-v+1)
                cout << "1\n";
            else
                cout << "0\n";
        }


        // for(int i = 1; i <= 15; i++)
        //     cout << st.tree[i] << ' ';
        // cout << '\n';
    }

    return 0;
}
