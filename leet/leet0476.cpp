// ACCEPTED!

int findComplement(int num)
    {
        vector<int> binary;

        while (num != 0)
        {
            binary.push_back(num%2);

            num /= 2;
        }

        long long k = 1, answer = 0;
        for (int x : binary)
        {
            answer += k*((x+1)%2);

            k *= 2;
        }

       return answer;
    }
