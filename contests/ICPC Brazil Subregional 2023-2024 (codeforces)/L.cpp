// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s; cin >> s;
	int k; cin >> k;

	vector<bool> change(s.size(), true);

	for(int i = 0; change[i] && s[i] != '\0'; i++)
	{
		priority_queue<int> v;

		for(int j = i; j < s.size(); j += k)
		{
			v.push(-s[j]);
			change[j] = false;
		}

		for(int j = i; j < s.size(); j += k, v.pop())
			s[j] = -v.top();
	}

	cout << s << endl;

	return 0;
}
