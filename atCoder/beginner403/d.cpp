#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001

int freq[MAX];

void edge_case_d_equals_zero()
{
    int answer = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (freq[i] > 0)
            answer += freq[i] - 1;
    }
    cout << answer << endl;
    return;
}

int f(vector<int> v)
{
    vector<int> dp(v.size()+1, 0);

    for (int i = v.size()-2; i >= 0; i--)
    {
        dp[i] = min(v[i]+dp[i+1], v[i+1]+dp[i+2]);
    }

    return dp[0];
}

int main ()
{
    int n, d;
    cin >> n >> d;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        freq[x]++;
    }

    if (d == 0)
    {
        edge_case_d_equals_zero();
        return 0;
    }

    int answer = 0;
    for (int i = 0; i < d; i++)
    {
        vector<int> v;
        for (int j = i; j < MAX; j += d)
        {
            v.push_back(freq[j]);
        }
        answer += f(v);
    }

    cout << answer << endl;

    return 0;
}
