// ACCEPTED!

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> nums3(m + n);

        int i, j, k;
        for (i = 0, j = 0, k = 0; i < m and j < n; k++)
        {
            if (nums1[i] <= nums2[j])
            {
                nums3[k] = nums1[i];
                i++;
            }
            else
            {
                nums3[k] = nums2[j];
                j++;
            }
        }

        while (i < m)
        {
            nums3[k] = nums1[i];
            i++;
            k++;
        }

        while (j < n)
        {
            nums3[k] = nums2[j];
            j++;
            k++;
        }

        for (int l = 0; l < (m + n); l++)
            nums1[l] = nums3[l];
    }
};
