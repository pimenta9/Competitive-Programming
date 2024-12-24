/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode* i = head;
        ListNode* j = head->next;

        ListNode* temp;
        while (j != nullptr)
        {
            while (j->val != 0)
            {
                i->val += j->val;

                temp = j;

                j = j->next;

                delete temp;
            }

            if (j->next == nullptr)
            {
                i->next = nullptr;
                break;
            }

            i->next = j;

            i = j;

            j = j->next;
        }

        return head;
    }
};
