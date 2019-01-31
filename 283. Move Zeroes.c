void moveZeroes(int* nums, int numsSize) {
    int i=0,j=0,temp;
    if (numsSize==1) return;                  // 單一索引直接回傳
    while (j<numsSize){
        if (!(*(nums+j)))                     // 找到數字0記下索引
            j++;
        else{
            temp=*(nums+i);                   // 兩數交換
            *(nums+i)=*(nums+j);
            *(nums+j)=temp;
            i++;
            j++;
        }
    }
}
