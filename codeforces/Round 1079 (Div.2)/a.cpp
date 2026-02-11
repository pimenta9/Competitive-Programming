#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

void solve ()
{
    int x; cin >> x;

    int nine = 999'999'999;

    while(nine)
    {
        if(x >= nine)
        {
            int digit = x / nine;
            if(digit > 9)
            {
                cout << "0\n";
                return;
            }
            x -= nine*digit;
        }

        nine /= 10;
    }

    if(x == 0)
        cout << "10\n";
    else
        cout << "0\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
