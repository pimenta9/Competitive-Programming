#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, answer = 0;
    cin >> n;

    vector<int> arr[n];
    map<vector<int>, bool> m;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;

        arr[i].resize(l);

        for (int j = 0; j < l; j++)
        {
            int a;
            cin >> a;

            arr[i][j] = a;
        }

        if (!m[arr[i]])
        {
            answer++;
        }

        m[arr[i]] = true;
    }

    cout << answer << endl;

    return 0;
}
