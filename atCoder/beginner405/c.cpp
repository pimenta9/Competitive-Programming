#include <bits/stdc++.h>
using namespace std;

#define MAX_N 300000

unsigned long long sum[MAX_N + 2];

int main ()
{
    int n;
    cin >> n;

    vector<unsigned long long> a(n+1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = n; i >= 2; i--)
    {
        sum[i] = sum[i+1] + a[i];
    }

    unsigned long long answer = 0;
    for (int i = 1; i <= n-1; i++)
    {
        answer += a[i]*sum[i+1];
    }

    cout << answer << endl;

    return 0;
}
