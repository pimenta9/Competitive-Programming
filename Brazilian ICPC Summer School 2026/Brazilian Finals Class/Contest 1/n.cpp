#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;

    while(a or b or c)
    {
        if(c - b == b - a)
        {
            cout << "AP " << c + (b-a) << '\n';
        }
        else
        {
            cout << "GP " << c * (c/b) << '\n';
        }

        cin >> a >> b >> c;
    }

    return 0;
}
