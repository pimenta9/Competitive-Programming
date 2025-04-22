#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    unsigned long long n;
    cin >> n;
 
    vector<unsigned long long> a(n);
    for (unsigned long long i = 0; i < n; i++)
        cin >> a[i];
 
    vector<unsigned long long> sum(n, 0);
    
    for (unsigned long long mask = 1 << 30; mask > 0; mask = mask >> 1)
    {
        unsigned long long num_zeroes = 0;
        unsigned long long num_ones = 0;
        for (unsigned long long i = 0; i < n; i++)
        {
            if (mask & a[i])
                num_ones++;
            else
                num_zeroes++;
        }
 
        for (unsigned long long i = 0; i < n; i++)
        {
            if (mask & a[i])
                sum[i] += num_zeroes*mask;
            else
                sum[i] += num_ones*mask;
        }
    }
 
    unsigned long long max = 0;
    for (unsigned long long i = 0; i < n; i++)
    {
        if (sum[i] > max)
            max = sum[i];
    }
 
    cout << max << endl;
}
 
int main ()
{
    int t;
    cin >> t;
 
    while (t--)
        solve();
 
    return 0;
}
