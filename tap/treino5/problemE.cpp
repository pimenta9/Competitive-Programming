#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    long long sum = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum = sum + x;

        m[x]++;
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        sum = sum + (b - a)* m[a];
        cout << sum << endl;

        m[b] += m[a];
        m[a] = 0;
    }

    return 0;
}
