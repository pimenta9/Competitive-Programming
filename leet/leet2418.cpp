// ACCEPTED!

vector<string> sortPeople(vector<string>& names, vector<int>& heights)
{
    int n = names.size();

    vector<pair<int, string>> aux;
    aux.resize(n);

    for (int i = 0; i < n; i++)
    {
        aux[i].first = -heights[i];
        aux[i].second = names[i];
    }

    sort(aux.begin(), aux.end());

    vector<string> answer;
    answer.resize(n);
    for (int i = 0; i < n; i++)
    {
        if (aux[i].second != "");
            answer.push_back(aux[i].second);
    }

    return answer;
}
