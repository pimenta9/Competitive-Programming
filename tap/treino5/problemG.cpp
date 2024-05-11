#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string str;
    cin >> str;

    vector<char> vec;
    vec.push_back('0');
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != vec.back())
        {
            vec.push_back(str[i]);
        }
        else
        {
            vec.pop_back();
        }
    }

    for (int i = 1; i < vec.size(); i++)
    {
        cout << vec[i];
    } cout << endl;

    return 0;
}
