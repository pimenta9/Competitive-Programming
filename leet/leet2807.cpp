// ACCEPTED!

class Solution {
public:
    int gcd(int a, int b)
    {
        if(b == 0)
            return a;

        return gcd(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        ListNode* nextNode = head->next, *ans = head;

        while(nextNode != nullptr)
        {
            head->next = new ListNode(gcd(head->val, nextNode->val), nextNode);

            head = nextNode;
            nextNode = nextNode->next;
        }

        return ans;
    }
};
