#include <bits/stdc++.h>
using namespace std;

int n;
vector<double> s;
vector<double> c;
vector<double> p;

vector<vector<double>> memo;

double f(int set, int x)
{
    if (memo[set][x] > 0) return memo[set][x];
    for (int i = 0; i < n; i++)
    {
        if (!(set&(1 << i)))
        {
            if (x >= c[i])
            {
                double success = (p[i]/100)*(s[i] + f(set+(1<<i), x-c[i]));
                double failure = (1-(p[i]/100))*(f(set, x-c[i]));
                memo[set][x] = max(memo[set][x], success+failure);
            }
        }
    }
    return memo[set][x];
}

int main ()
{
    int x;
    cin >> n >> x;
    memo.resize(1 << n, vector<double>(x+1, 0));
    s.resize(n);
    c.resize(n);
    p.resize(n);
    for (int i = 0; i < n; i++)
    {
        double score, cost, probability;
        cin >> score >> cost >> probability;
        s[i] = score;
        c[i] = cost;
        p[i] = probability;
    }

    printf("%.20lf\n", f(0, x));

    return 0;
}
