#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, m;
    cin >> n >> m;

    int A[n], B[m];

    for(int i = 0; i < n; i++)
        cin >> A[i];

    for(int i = 0; i < m; i++)
        cin >> B[i];

    sort( A, A + n );
    sort( B, B + m );

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    for(int i = 0; i < m; i++)
        cout << B[i] << " ";
    cout << endl;
    return 0;
}