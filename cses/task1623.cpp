// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;
 
int main ()
{
    int n;
    cin >> n;
 
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
 
    long long min;
    for (int i = 0; i < (1 << n); i++)
    {
        long long a = 0;
        long long b = 0;
 
        for (int mask = 1, j = 0; mask < (1 << n); mask = mask << 1, j++)
        {
            if (i & mask)
                a += p[j];
            else
                b += p[j];
        }
 
        if (i == 0 or abs(a - b) < min)
            min = abs(a - b);
    }
 
    cout << min << endl;
 
    return 0;
}
