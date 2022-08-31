/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while (temp1 != temp2) {
            if (temp1 == NULL) {
                temp1 = headB;
            } else {
                temp1 = temp1->next;
            }
            if (temp2 == NULL) {
                temp2 = headA;
            } else {
                temp2 = temp2->next;
            }

        }
        return temp1;
    }
};


//2nd soln;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getCount(ListNode* head)
    {
        ListNode* current = head;

        // Counter to store count of nodes
        int count = 0;

        // Iterate till NULL
        while (current != NULL) {

            // Increase the counter
            count++;

            // Move the Node ahead
            current = current->next;
        }

        return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int l1 = getCount(headA);
        int l2 = getCount(headB);

        if (l1 < l2) {
            for (int i = 0; i < (l2 - l1); i++) {
                temp2 = temp2->next;
            }
        } else {
            for (int i = 0; i < (l1 - l2); i++) {
                temp1 = temp1->next;
            }
        }

        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};