#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v(n);
    int maior = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        maior = max(maior, v[i]);
    }

    sort(v.begin(), v.end());

    vector<int> ans, u;

    for(int x : v)
    {
        if(x == maior) break;
        u.push_back(x);
    }

    if(n % 2 == 0)
    {
        int sum = v[0] + v[n-1];

        bool ok = true;
        for(int i = 0, j = n-1; i < j; i++, j--)
        {
            if(v[i] + v[j] != sum)
            {
                ok = false;
                break;
            }
        }

        if(ok) ans.push_back(sum);
    }

    int m = u.size();
    if(m == 0)
    {
        ans.push_back(maior);
    }
    else if(m % 2 == 0)
    {
        int sum = u[0] + u[m-1];

        bool ok = true;
        for(int i = 0, j = m-1; i < j; i++, j--)
        {
            if(u[i] + u[j] != sum)
            {
                ok = false;
                break;
            }
        }

        if(ok) ans.push_back(sum);
    }

    sort(ans.begin(), ans.end());

    for(int x : ans) cout << x << ' ';
    cout << '\n';

    return 0;
}
