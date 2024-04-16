#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, x;
    cin >> n >> x;

    vector<pair<int, int> > vec;

    int y;
    for (int i = 1; i <= n; i++)
    {
        cin >> y;
        vec.push_back(make_pair(y, i));
    }

    sort(vec.begin(), vec.end());

    int i = 0, j = (n - 1), sum;
    while (j > i)
    {
        sum = vec[i].first + vec[j].first;

        if (sum == x)
        {
            cout << vec[i].second << " " << vec[j].second << endl;
            return 0;
        }

        if (sum > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}