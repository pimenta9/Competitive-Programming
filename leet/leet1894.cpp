// ACCEPTED!

int chalkReplacer(vector<int>& chalk, int k)
{
    long sum = 0;
    for(int x : chalk)
        sum += x;

    k = k % sum;

    for(int i = 0; i < chalk.size(); i++)
    {
        k -= chalk[i];

        if(k < 0)
            return i;
    }

    return -1;
}
