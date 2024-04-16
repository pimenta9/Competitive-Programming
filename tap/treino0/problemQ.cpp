#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, k;
    cin >> n >> k;

    int x, n2 = n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;

        if (x > (5 - k))
        {
            n2--;
        }
    }
    cout << (n2 / 3) << endl;

    return 0;
}