#include <bits/stdc++.h>
using namespace std;

#define int long long

int block_size;
vector<int> v;
int global_ans;

struct Query
{
    int l, r, idx;

    Query (int l, int r, int idx)
    {
        this->l = l, this->r = r, this->idx = idx;
    }

    bool operator <(Query other)
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

void add(int idx)
{
    // todo
}

void remove(int idx)
{
    // todo
}

int get_answer()
{
    // todo
}

vector<int> mo_s_algorithm(vector<Query> queries)
{
    vector<int> ans(size(queries));
    sort(queries.begin(), queries.end());

    int l = 0, r = -1;

    for(Query q : queries)
    {
        while(l < q.l) remove(l++);
        while(l > q.l) add(--l);
        while(r > q.r) remove(r--);
        while(r < q.r) add(++r);

        ans[q.idx] = get_answer();
    }

    return ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    block_size = (int) sqrt(n + .0);

    v.resize(n);
    for(int& x : v) cin >> x;

    vector<Query> queries;
    for(int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        queries.emplace_back(--l, --r, i);
    }

    vector<int> ans = mo_s_algorithm(queries);

    for(int x : ans) cout << x << '\n';

    return 0;
}
