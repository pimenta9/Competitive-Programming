// AtCoder abc164_c

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;

        m[s]++;
    }

    cout << m.size() << endl;

    return 0;
}
