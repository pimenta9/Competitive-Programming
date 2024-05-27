// ACCEPTED!

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;

    struct ListNode* next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* l3 = malloc(sizeof(struct ListNode));
    struct ListNode* aux1 = l1;
    struct ListNode* aux2 = l2;
    struct ListNode* aux3 = l3;

    int sum, ten = 0, s1, s2;
    while (1)
    {
        if (aux1 == NULL) s1 = 0;
        else s1 = aux1->val;

        if (aux2 == NULL) s2 = 0;
        else s2 = aux2->val;
        
        sum = s1 + s2 + ten;

        if (sum >= 10)
        {
            ten = 1;
            sum -= 10;
        }
        else
        {
            ten = 0;
        }

        aux3->val = sum;
        aux3->next = NULL;

        // update loop

        if (aux1 != NULL)
            aux1 = aux1->next;
        if (aux2 != NULL)
            aux2 = aux2->next;

        if (aux1 == NULL && aux2 == NULL && ten == 0)
        {
            break;
        }
        else
        {
            aux3->next = malloc(sizeof(struct ListNode));
            aux3 = aux3->next;
        }
    }

    return l3;
}

void printList (struct ListNode* listHead)
{
    for (struct ListNode* aux = listHead; aux != NULL; aux = aux->next)
    {
        printf ("%d -> ", aux->val);
    } printf("//\n");
}

int main ()
{
    struct ListNode* l1 = malloc(sizeof(struct ListNode));

    l1->val = 2;
    l1->next = malloc(sizeof(struct ListNode));

    (l1->next)->val = 4;
    (l1->next)->next = malloc(sizeof(struct ListNode));

    ((l1->next)->next)->val = 3;
    ((l1->next)->next)->next = NULL;

    // printList(l1);

    struct ListNode* l2 = malloc(sizeof(struct ListNode));

    l2->val = 5;
    l2->next = malloc(sizeof(struct ListNode));

    (l2->next)->val = 6;
    (l2->next)->next = malloc(sizeof(struct ListNode));

    ((l2->next)->next)->val = 4;
    ((l2->next)->next)->next = NULL;

    // printList(l2);

    struct ListNode* l3 = addTwoNumbers(l1, l2);

    printList (l3);

    return 0;
}