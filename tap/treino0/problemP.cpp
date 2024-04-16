#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    int v[n], x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;

        v[x - 1] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}