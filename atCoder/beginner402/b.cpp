#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    queue<int> q;

    while (n--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int x; cin >> x;
            q.push(x);
        }
        else
        {
            cout << q.front() << endl;
            q.pop();
        }
    }

    return 0;
}
