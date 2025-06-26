/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* answer = nullptr;
        ListNode* tail = nullptr;
        int leftover = 0;
        int sum = 0;

        while (temp1 != NULL || temp2 != NULL) {
            if (temp1 == NULL) {
                sum = temp2->val + leftover;
                temp2 = temp2->next;
            } else if (temp2 == NULL) {
                sum = temp1->val + leftover;
                temp1 = temp1->next;
            } else {
                sum = temp1->val + temp2->val + leftover;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            ListNode* newNode = new ListNode();
            newNode->next = nullptr;

            if (answer == nullptr) {
                answer = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            
            if (sum >= 10) {
                tail->val = sum - 10;
                leftover = 1;
            } else {
                tail->val = sum;
                leftover = 0;
            }
        }

        if (leftover == 1) {
            ListNode* newNode = new ListNode();
            newNode->next = nullptr;
            tail->next = newNode;
            tail = newNode;
            tail->val = leftover;
        }
        return answer;
    }
};