#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main ()
{
    int n;
    cin >> n;
 
    int ans = 0;
 
    int aux = 5;
 
    while (n >= aux)
    {
        ans += n/aux;
 
        aux *= 5;
    }
 
    cout << ans << '\n';
 
    return 0;
}
