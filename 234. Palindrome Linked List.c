/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode list;
bool isPalindrome(struct ListNode* head) {
    int total=0,i=0,*palindrome=NULL;
    list *tail=head;
    while (tail!=NULL){
        total++;
        tail=tail->next;
    }
    palindrome=malloc(sizeof(int)*total);                    // 將 link list 依序放入 array 中
    tail=head;
    while (tail!=NULL){
        *(palindrome+i++)=tail->val;
        tail=tail->next;
    }
    if (total==1) return 1;
    else{
        total--;                                             // 再從頭尾比較,相同則代表有回文
        for (i=0;i<total;i++,total--){
            if (*(palindrome+i)==*(palindrome+total)){
                continue;
            }else{
                return 0;
            }
        }
        return 1;
    }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
bool isPalindrome(struct ListNode* head) {
    if ((head == NULL) || (head->next == NULL)) return true;

    struct ListNode *head2 = head;
    int length = 1;
    while (head2->next != NULL) {
        head2 = head2->next;
        length++;
    }

    struct ListNode *node2 = head;
    head2 = head->next;
    int k = length/2;
    while (k > 1) {
        node2 = node2->next;
        head2 = head2->next;
        k--;
    }

    if (length%2 != 0)
        head2 = head2->next;
    node2->next = NULL;

    //printf("%d, %d", node2->val, head2->val);

    struct ListNode *node1 = head;
    struct ListNode *tmp1;
    struct ListNode *tmp2;
    while (node1 != node2) {
        tmp2 = node2->next;
        tmp1 = node1->next;
        node2->next = node1;
        node2->next->next = tmp2;
        node1 = tmp1;
    }

    while (node1->val == head2->val) {
        node1 = node1->next;
        head2 = head2->next;
        if ((node1 == NULL) || (head2 == NULL))
            return true;
    }

    return false;
}
*/
