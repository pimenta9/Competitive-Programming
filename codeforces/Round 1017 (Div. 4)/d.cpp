#include <bits/stdc++.h>
using namespace std;
 
vector<long long> func(string str)
{
    vector<long long> answer;
    long long size = 1, i;
    for (i = 1; i < str.size(); i++)
    {
        if (str[i] == str[i-1])
            size++;
        else
        {
            if (str[i-1] == 'L')
                answer.push_back(-size);
            else
                answer.push_back(size);
            size = 1;
        }
    }
    if (str[i-1] == 'L')
        answer.push_back(-size);
    else
        answer.push_back(size);
    return answer;
}
 
int main ()
{
    int t;
    cin >> t;
 
    while (t--)
    {
        bool no = false;
        string p, s;
        cin >> p >> s;
 
        vector<long long> vec_p = func(p);
        vector<long long> vec_s = func(s);
 
        if (vec_p.size() != vec_s.size())
        {
            no = true;
        }
        else
        {
            for (long long i = 0; i < vec_p.size(); i++)
            {
                long long aux = vec_p[i]*vec_s[i];
                if (aux > 0)
                {
                    long long x = abs(vec_p[i]);
                    long long y = abs(vec_s[i]);
 
                    if (y < x or y > 2*x)
                        no = true;
                }
                else
                {
                    no = true;
                }
            }
        }
 
        if (no)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
 
    return 0;
}
