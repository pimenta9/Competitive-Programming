#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX_SIZE = 3e5;

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    vector<int> v(MAX_SIZE);

    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;

        v[x]++;
        v[0]--;
    }

    for(int i = MAX_SIZE-2; i >= 0; i--)
    {
        v[i] = v[i] + v[i+1];
    }

    for(int i = 1; i < MAX_SIZE-1; i++)
    {
        v[i+1] += v[i]/10;
        v[i] = v[i] % 10;
    }

    bool ok = false;
    for(int i = MAX_SIZE-1; i > 0; i--)
    {
        if(v[i]) ok = true;
        if(ok) cout << v[i];
    }

    cout << '\n';
    
    return 0;
}
