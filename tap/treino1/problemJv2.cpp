#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    long long k;
    cin >> n >> k;

    vector<pair<long long, int> > vec;

    long long aux;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;

        vec.push_back(make_pair(aux, i));
    }

    sort(vec.begin(), vec.end());

    int i = 0;
    while (vec[i].first == 0)
    {
        i++;
    }

    long long x = vec[i].first;

    long long temp = (x*(n - i));

    while (temp <= k)
    {
        for (int j = i; j < n; j++)
        {
            vec[j].first -= x;
            k -= x;
        }
        if (k == 0) break;

        while (vec[i].first == 0)
        {
            i++;
        }
        x = vec[i].first;
    }
    
    long long answer[n];
    int nonZeroes = 0;
    for (int j = 0; j < n; j++)
    {
        answer[vec[j].second] = vec[j].first;

        if (vec[j]. first > 0)
            nonZeroes++;
    }

    long long y = k/nonZeroes, r = k%nonZeroes;
    for (int l = 0; l < n; l++)
    {
        if (answer[l] > 0)
        {
            answer[l] -= y;
        }
    }

    if (r != 0)
    {
        int j = 0;
        while (k > 0)
        {
            if (answer[j] > 0)
            {
                answer[j]--;
                k--;
            }
            j++;
        }
    }

    for (int j = 0; j < n; j++)
    {
        cout << answer[j] << " ";
    } cout << endl;
    
    return 0;
}