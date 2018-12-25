/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* current=node;
    if (current==NULL) return;
    current->val=current->next->val;
    current->next=current->next->next;
}
