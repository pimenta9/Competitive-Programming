#include <bits/stdc++.h>
using namespace std;

double sqrt10(int n)
{
    if(n == 0) return 0;
    
    return 1/(6 + sqrt10(n - 1));
}

int main ()
{
    int n; cin >> n;
    
    printf("%.10lf\n", 3 + sqrt10(n));
    
    return 0;
}
