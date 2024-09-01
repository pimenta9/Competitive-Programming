// ACCEPTED!

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n)
{
    if(original.size() != n*m) return {};

    vector<vector<int>> array2D(m, vector<int>(n));

    for(int i = 0; i < original.size(); i++)
    {
        array2D[i/n][i%n] = original[i];
    }

    return array2D;
}
