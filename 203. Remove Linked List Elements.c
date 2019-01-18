/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *current=head;         // pointer to head node
    struct ListNode *previous=NULL;        // pointer to NULL
    if (!head) return head;                // 如果為空,直接回傳NULL
    while (head->val==val){                // head node value == val
        head=head->next;
        free(current);                     // current記得head上一次的location
        current=head;                      // current pointer to head node 當前位址
        if (!head) return head;            // 如果已為空,return NULL
    }                                      // 以上為預防前面的連續符合需求之節點
    //if (!current) return head;
    previous=head;
    current=head->next;
    if (!current) return head;
    while (current){
        if (current->val==val){
            previous->next=current->next;  // previous next 直接指向 current next
            free(current);                 // 刪除current
            current=previous->next;        // current pointer to previous next
        }else{
            previous=previous->next;
            current=current->next;
        }
        if (!current) return head;
    }
    return head;
}
