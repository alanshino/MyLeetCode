/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {   // 使用取負數法
    int *preturn=malloc(sizeof(int)*numsSize);                            // 直接分配 numsSize memory storage
    int i=0,block;                                                        // 紀錄索引值
    for (i=0;i<numsSize;i++){
        block=abs(*(nums+i))-1;
        *(nums+block)=(*(nums+block))>0?-*(nums+block):*(nums+block);     // 是正數就改成負數
    }
    *returnSize=0;
    for (i=0;i<numsSize;i++){
        if (*(nums+i)>0){                                                 // 找到正數代表沒對應到
            *(preturn+*returnSize)=i+1;                                   // 將值放入,索引從0開始
            (*returnSize)++;                                              // *returnSize 增加讓回傳取值
        }
    }
    return preturn;
}
