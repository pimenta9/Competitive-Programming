// ACCEPTED! (beats 100%)

class Solution {
public:
    vector<string> splitWords(string s)
    {
        vector<string> words;

        int i, j;
        for(i = 0; i < s.size(); i = j + 1)
        {
            string str;
            for(j = i; s[j] != ' ' and s[j] != '\0'; j++)
            {
                str.push_back(s[j]);
            }

            words.push_back(str);
        }

        return words;
    }

    vector<string> uncommonFromSentences(string s1, string s2)
    {
        map<string, int> wordFreq;

        vector<string> v1 = splitWords(s1);
        for(string s : v1)
            wordFreq[s]++;

        vector<string> v2 = splitWords(s2);
        for(string s : v2)
            wordFreq[s]++;

        vector<string> uncommonWords;

        while(!wordFreq.empty())
        {
            string s = (*wordFreq.begin()).first;
            int freq = (*wordFreq.begin()).second;

            wordFreq.erase(s);

            if(freq == 1)
                uncommonWords.push_back(s);
        }

        return uncommonWords;
    }
};
