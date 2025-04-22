#include <bits/stdc++.h>
using namespace std;
 
int main ()
{
    int t;
    cin >> t;
 
    while (t--)
    {
        int n, m, l, r;
        cin >> n >> m >> l >> r;
 
        for (int i = 0; i < n-m; i++)
        {
            if (abs(l) > r)
                l++;
            else
                r--;
        }
 
        cout << l << " " << r << endl;
    }
 
    return 0;
}
