#include <bits/stdc++.h>
using namespace std;

string t, u;

bool check (int i)
{
    for (int j = i, k = 0; k < u.size(); j++, k++)
    {
        if (j >= t.size() or (u[k] != t[j] and t[j] != '?'))
            return false;
    }
    return true;
}

int main ()
{
    cin >> t >> u;

    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '?' or t[i] == u[0])
        {
            if (check(i))
            {
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No\n";

    return 0;
}
