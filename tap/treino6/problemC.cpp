// AtCoder abc073_c

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n; cin >> n;

    map<int, bool> m;
    
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;

        if (m[x] == true)
        {
            m.erase(x);
        }
        else
        {
            m[x] = true;
        }
    }

    cout << m.size() << endl;

    return 0;
}
