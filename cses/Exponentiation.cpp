// Accepted!

#include <bits/stdc++.h>
using namespace std;
 
#define ull unsigned long long
 
#define MOD 1000000007
 
void solve()
{
    ull a, b;
    cin >> a >> b;
 
    ull answer = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            answer = (answer%MOD * a%MOD) % MOD;
        }
        a = (a%MOD * a%MOD) % MOD;
 
        b = b >> 1;
    }
 
    cout << answer << endl;
}
 
int main ()
{
    int n;
    cin >> n;
 
    while (n--)
        solve();
 
    return 0;
}
