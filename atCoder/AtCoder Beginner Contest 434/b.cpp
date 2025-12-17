#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    map<int, double> freq, size;

    for (int i = 0; i < n; i++)
    {
        int a; double b;
        cin >> a >> b;

        freq[a]++;
        size[a] += b;
    }

    for (int i = 1; i <= m; i++)
    {
        cout << setprecision(5) << size[i] / freq[i] << '\n';
    }

    return 0;
}