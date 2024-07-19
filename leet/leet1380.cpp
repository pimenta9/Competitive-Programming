// ACCEPTED!

int min_index (vector<int> arr)
{
    int min = arr[0], minIndex = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            minIndex = i;
        }
    }

    return minIndex;
}

vector<int> luckyNumbers (vector<vector<int>>& matrix)
{
    int rows = matrix.size();
    int columns = matrix[0].size();

    vector<int> answer;

    for (int i = 0; i < rows; i++)
    {
        int minIndex = min_index(matrix[i]);

        for (int j = 0; j < rows; j++)
        {
            if (matrix[j][minIndex] > matrix[i][minIndex])
            {
                goto next_for;
            }
        }

        answer.push_back(matrix[i][minIndex]);

        next_for:
        ;
    }

    return answer;
}
