int searchInsert(int* nums, int numsSize, int target) {
    int i=0;
    for (i=0;i<numsSize;i++){
        if (*(nums+i)==target||*(nums+i)>target){  // 如果找到位置,或是發現已經超過
            return i;
        }
    }
    return numsSize;                               // 都沒找到合適或相等,補在最後
}
