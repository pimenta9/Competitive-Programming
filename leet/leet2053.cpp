// ACCEPTED!

string kthDistinct(vector<string>& arr, int k)
{
    map<string, int> m;

    for (string s : arr)
    {
        m[s]++;
    }

    for (string s : arr)
    {
        if (m[s] == 1)
        {
            if (k == 1)
                return s;

            k--;
        }
    }

    return "";
}
