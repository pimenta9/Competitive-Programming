#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, int> m;
    int a = 0, b = 0, current = 0;
    long long answer = 0;
    for ( ; b < n; b++)
    {
        if (m[arr[b]] == 0) current++;
        m[arr[b]]++;

        while (current > k)
        {
            m[arr[a]]--;
            if (m[arr[a]] == 0) current--;
            a++;
        }

        answer += b - a + 1;
    }

    cout << answer << endl;

    return 0;
}
