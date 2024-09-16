// ACCEPTED! beats 98%

class Solution {
public:
    int format(string s)
    {
        int minutes = 0;

        minutes += (s[0] - '0') * 600;
        minutes += (s[1] - '0') * 60;
        minutes += (s[3] - '0') * 10;
        minutes += (s[4] - '0');

        return minutes;
    }

    void bucketSort(vector<int>& arr, int possibleValues)
    {
        vector<int> buckets(possibleValues, 0);

        for(int x : arr)
            buckets[x]++;

        arr.resize(0);

        for(int i = 0; i < possibleValues; i++)
        {
            while(buckets[i]--)
                arr.push_back(i);
        }
    }

    int findMinDifference(vector<string>& timePoints)
    {
        vector<int> points;

        for(string s : timePoints)
            points.push_back(format(s));

        bucketSort(points, 1440);

        points.push_back(points[0] + 24*60);

        int minDifference = 0x7FFFFFFF;

        int previous = points[0];
        for(int i = 1; i < points.size(); i++)
        {
            int current = points[i];

            int diff = current - previous;

            if(diff < minDifference)
                minDifference = diff;

            previous = current;
        }

        return minDifference;
    }
};
