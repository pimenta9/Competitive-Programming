#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, m, x, y = 0;
    cin >> n >> m;

    vector<pair<int, int> > vec;

    for (int i = 0; i < (n + m); i++)
    {
        cin >> x;
        if (i == n) y = 1;
        vec.push_back(make_pair(x, y));
    }

    sort(vec.begin(), vec.end());

    int i = 0, answer = 1000000001, diff;
    while (i < ((n + m) - 1))
    {
        while (vec[i + 1].second == vec[i].second)
        {
            i++;

            if (i >= ((n + m) - 1))
            {
                break;
            }
        }
        if (i >= ((n + m) - 1))
        {
            break;
        }

        diff = vec[i + 1].first - vec[i].first;
        if (diff < answer) answer = diff;

        i++;

        // cout << answer << endl;
    }

    cout << answer << endl;

    return 0;
}