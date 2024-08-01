// ACCEPTED!

int countSeniors(vector<string>& details)
    {
        int answer = 0;

        for(string s : details)
        {
            char age[3];
            age[0] = s[11];
            age[1] = s[12];
            age[2] = '\0';
            if (stoi(age) > 60)
                answer++;
        }

        return answer;
    }
