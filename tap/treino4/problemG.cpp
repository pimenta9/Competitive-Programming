#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, x;
    cin >> n >> x;

    int a[n];
    for (int i = 0; i < (n); i++)
    {
        cin >> a[i];
    }

    long long p = 0, find, count = 0;
    map<long long, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++)
    {
        p += a[i];
        find = p - x;
        count += m[find];
        m[p]++;
    }

    cout << count << endl;

    return 0;
}
