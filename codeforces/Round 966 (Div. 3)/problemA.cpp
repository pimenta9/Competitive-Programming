#include <bits/stdc++.h>
using namespace std;
 
int str2int(string s)
{
    int n = 0;
    for (int i = s.size()-1, j = 1; i >= 0; i--, j *= 10)
    {
        n += (s[i] - '0')*j;
    }
 
    return n;
}
 
int main ()
{
    int t; cin >> t;
 
    while(t--)
    {
        string s; cin >> s;
 
        if (s[0] == '1' && s[1] == '0')
        {
            if(s[2] == '0')
            {
                cout << "no\n";
                continue;
            }
 
            string aux;
            for(int i = 2; s[i] != '\0'; i++)
            {
                aux.push_back(s[i]);
            }
            if(str2int(aux) >= 2)
                cout << "yes\n";
            else
                cout << "no\n";
        }
        else
            cout << "no\n";
    }
 
    return 0;
}
