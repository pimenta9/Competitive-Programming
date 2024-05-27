// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    vector<char> aux;

    for (int i = 0; i < s.size(); i++)
    {
        if (aux.empty())
            aux.push_back(s[i]);
        else
        {
            if ((s[i] == ')' && aux.back() == '(') || s[i] == (aux.back() + 2))
            {
                aux.pop_back();
            }
            else
            {
                aux.push_back(s[i]);
            }
        }
    }

    return (aux.empty());
}

int main ()
{
    string str = {"({[()]}"};

    cout << isValid(str) << endl;

    return 0;
}