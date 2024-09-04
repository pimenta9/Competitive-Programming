// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

vector<int> v, a, b;
int n;
vector<vector<bool>> isFalse;

bool findSumIndexes(int i, int t)
{
    if(t == 0) return true;
    if(i >= n || t < 0) return false;

    if(isFalse[t][i]) return false;

    bool include = findSumIndexes(i+1, t-v[i]);
    if(include)
    {
        a.push_back(i);
        return true;
    }

    bool exclude = findSumIndexes(i+1, t);

    isFalse[t][i] = !exclude;
    return exclude;
}

int main ()
{
    int sum = 0;
    cin >> n;
    v.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    if(sum % 2)
    {
        cout << "-1\n";
        return 0;
    }

    sum /= 2;

    isFalse.resize(sum+1);
    for(int i = 0; i <= sum; i++)
        isFalse[i].resize(n, false);

    findSumIndexes(0, sum);

    int i, j;
    for(i = n-1, j = 0; i >= 0 && j < a.size(); i--)
    {
        if(i != a[j])
            b.push_back(i);
        else
            j++;
    }
    while(i >= 0)
    {
        b.push_back(i);

        i--;
    }

    int sumAlice = 0;
    for(int x : a)
        sumAlice += v[x];

    if(sumAlice != sum)
    {
        cout << "-1\n";
        return 0;
    }

    int alice = 0, bob = 0, indexA = 0, indexB = 0;
    for(int k = 0; k < n; k++)
    {
        if(k) cout << " ";

        if(alice <= bob)
        {
            cout << v[a[indexA]];
            alice += v[a[indexA]];
            indexA++;
        }
        else
        {
            cout << v[b[indexB]];
            bob += v[b[indexB]];
            indexB++;
        }
    }
    cout << endl;

    return 0;
}
