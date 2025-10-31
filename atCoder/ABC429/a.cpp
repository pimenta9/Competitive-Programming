#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cout << ( i > m ? "Too Many Requests\n" : "OK\n" );
    }

    return 0;
}
