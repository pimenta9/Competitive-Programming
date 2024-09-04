// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, h;
    cin >> n >> h;

    int ans = 0;
    while(n--)
    {
        int aux; cin >> aux;

        if(aux <= h)
            ans++;
    }

    cout << ans << endl;

    return 0;
}
