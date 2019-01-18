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
    if (!head) return head;                // �p�G����,�����^��NULL
    while (head->val==val){                // head node value == val
        head=head->next;
        free(current);                     // current�O�ohead�W�@����location
        current=head;                      // current pointer to head node ��e��}
        if (!head) return head;            // �p�G�w����,return NULL
    }                                      // �H�W���w���e�����s��ŦX�ݨD���`�I
    //if (!current) return head;
    previous=head;
    current=head->next;
    if (!current) return head;
    while (current){
        if (current->val==val){
            previous->next=current->next;  // previous next �������V current next
            free(current);                 // �R��current
            current=previous->next;        // current pointer to previous next
        }else{
            previous=previous->next;
            current=current->next;
        }
        if (!current) return head;
    }
    return head;
}
