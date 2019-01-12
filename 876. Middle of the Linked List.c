/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    int val=0;
    struct ListNode *var=head;
    while (var!=NULL){
        val++;
        var=var->next;
    }
    if (val%2){
        val=val/2;   
    }else{
        val=val/2;
    }
    var=head;
    while (val){
        var=var->next;
        val--;
    }
    return var;
}
