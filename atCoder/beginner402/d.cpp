#include <bits/stdc++.h>
using namespace std;

int main ()
{
    long long n, m;
    cin >> n >> m;

    long long a, b;
    cin >> a >> b;
    long long pairs = 1;
    long long answer = 0;
    vector<long long> v(n);
    v[(a+b)%n]++;
    for (long long i = 1; i < m; i++)
    {
        answer += pairs;
        pairs++;
        cin >> a >> b;
        answer -= v[(a+b)%n];
        v[(a+b)%n]++;
    }

    cout << answer << endl;

    return 0;
}
