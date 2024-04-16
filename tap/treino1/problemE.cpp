#include <bits/stdc++.h>
using namespace std;

int howManyGreater(int x, int arr[], int size)
{
    int a = 0, b = (size - 1), c;

    while (b >= a)
    {
        c = (a + b)/2;

        if (arr[c] == x) return (size - c);

        if (x < arr[c])
            b = c - 1;
        else
            a = c + 1;
    }

    return (size - a);
}

int main ()
{
    int n, q;
    cin >> n >> q;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int answer = 0, x;

    for (int i = 0; i < q; i++)
    {
        cin >> x;

        cout << howManyGreater(x, arr, n) << endl;
    }

    return 0;
}