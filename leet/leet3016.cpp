// ACCEPTED!

int minimumPushes(string word)
{
    vector<int> letters(26, 0);

    for (char c : word)
    {
        letters[c - 'a']--;
    }

    sort(letters.begin(), letters.end());

    int answer = 0;

    for (int i = 0; i < 26; i++)
    {
        answer += -letters[i] * ((i/8) + 1);
    }

    return answer;
}
