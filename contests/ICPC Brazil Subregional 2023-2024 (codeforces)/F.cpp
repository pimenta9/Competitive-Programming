// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int d, c, r;
    cin >> d >> c >> r;

    queue<int> q;

    while(c--)
    {
        int aux; cin >> aux;

        q.push(aux);
    }

    int ans = r;

    while(r--)
    {
        int aux; cin >> aux;

        d += aux;
    }

    while(!q.empty() && q.front() <= d)
    {
        ans++;

        d -= q.front();
        q.pop();
    }

    cout << ans << endl;

    return 0;
}
