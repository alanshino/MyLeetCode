/* 2. Add Two Numbers */
/**
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example:
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *temp = l1;
    struct ListNode *return_node = NULL;
    struct ListNode *head = NULL;
    int count1 = 0;
    int count2 = 0;
    int count = 0;
    int carry = 0;
    while (temp) {
        count1++;
        temp = temp->next;
    }
    temp = l2;
    while (temp) {
        count2++;
        temp = temp->next;
    }
    count = (count1 > count2)? count1:count2;
    while (count) {
        temp = malloc(sizeof(struct ListNode));
        if (head) {
            return_node->next = temp;
            if (l1 && l2) {
                temp->val = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                temp->val = l1->val + carry;
                l1 = l1->next;
            } else {
                temp->val = l2->val + carry;
                l2 = l2->next;
            }
            if (temp->val >= 10) {
                carry = temp->val / 10;
                temp->val = temp->val % 10;
            } else {
                carry = 0;
            }

            return_node = return_node->next;
        } else {
            head = return_node = temp;
            if (l1 && l2) {
                return_node->val = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                return_node->val = l1->val;
                l1 = l1->next;
            } else {
                return_node->val = l2->val;
                l2 = l2->next;
            }
            if (return_node->val >= 10) {
                carry = return_node->val / 10;
                return_node->val = return_node->val % 10;
            }

        }
        count--;
    }
    if (carry) {
        temp = malloc(sizeof(struct ListNode));
        return_node->next = temp;
        temp->val = carry;
    }
    temp->next = NULL;
    return head;
}
