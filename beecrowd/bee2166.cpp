#include <bits/stdc++.h>
using namespace std;

double sqrt2(int n)
{
    if (n == 0) return 0;
    
    return 1/(2 + sqrt2(n - 1));
}

int main ()
{
    int n; cin >> n;
    
    printf("%.10lf\n", 1 + sqrt2(n));
    
    return 0;
}
