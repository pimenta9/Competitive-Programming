#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    map<int, bool> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        m[a] = true;
    }

    for (int i = 0; i <= 2000; i++)
    {
        if (!m[i])
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << "2001\n";
    
    return 0;
}
