#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    string t, a;
    cin >> t >> a;

    for (int i = 0; i < n; i++)
    {
        if (t[i] == 'o' and a[i] == 'o')
        {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

    return 0;
}
