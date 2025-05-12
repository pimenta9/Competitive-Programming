#include <bits/stdc++.h>
using namespace std;

int freq[101];

int main ()
{
    int n, m;
    cin >> n >> m;

    int seen = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (freq[a[i]] == 0)
        {
            seen++;
        }
        freq[a[i]]++;
    }

    if (seen != m)
    {
        cout << "0\n";
        return 0;
    }

    int answer = 0;
    for (int i = n-1; i >= 0; i--)
    {
        answer++;
        freq[a[i]]--;
        if (freq[a[i]] == 0)
        {
            cout << answer << endl;
            return 0;
        }
    }

    return 0;
}
