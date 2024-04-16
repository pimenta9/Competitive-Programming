#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    long long k;
    cin >> n >> k;

    vector<pair<long long, int> > vec;

    long long temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;

        vec.push_back(make_pair(temp, i));
    }

    sort(vec.begin(), vec.end());

    int i = 0;
    while (vec[i].first == 0)
    {i++;}

    long long aux, sum = 0;
    while (k >= (n - i))
    {
        aux = k / (n - i);
        k = k % (n - i);

        for (int j = i; j < n; j++)
        {
            if (vec[j].first < aux)
            {
                vec[j].first = 0;
                k += vec[j].first;
            }
            else
            {
                vec[j].first -= aux;
            }
        }

        while (vec[i].first == 0)
        {i++;}
    }

    long long answer[n];
    for (int k = 0; k < n; k++)
    {
        answer[vec[k].second] = vec[k].first;
    }

    for (int k = 0; k < n; k++)
    {
        cout << vec[k].first << " ";
    } cout << endl;

    return 0;
}