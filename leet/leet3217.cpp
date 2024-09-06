// ACCEPTED!

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        map<int, bool> inNums;

        for (int x : nums)
            inNums[x] = true;

        while (inNums[head->val])
            head = head->next;

        ListNode *last = head, *current = head->next;

        while (current != NULL)
        {
            if (inNums[current->val])
                last->next = current->next;

            else
                last = current;

            current = current->next;
        }

        return head;
    }
};
