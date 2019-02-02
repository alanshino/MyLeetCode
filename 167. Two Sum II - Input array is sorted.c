/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i=0,j;
    int *preturn=NULL;
    *returnSize=2;
    preturn=malloc(sizeof(int)**returnSize);
    for (i=0;i<numbersSize;i++){                                  // 逐一比較,遇到自己的索引就跳過
        for (j=0;j<numbersSize;j++){
            if (j==i)
                continue;
            else{
                if ((*(numbers+i)+*(numbers+j))==target){         // 放如回傳陣列
                    *(preturn+0)=i+1;
                    *(preturn+1)=j+1;
                    return preturn;
                }
            }
        }
    }
    return preturn;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().  // faster
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    if (numbers == NULL || numbersSize < 2) return NULL;
    int idx1 = 0, idx2 = numbersSize-1;
    while(numbers[idx1] + numbers[idx2] != target || idx1 >= idx2)
    {
        if (numbers[idx1] + numbers[idx2] < target)
        {
            ++idx1;
        }
        if (numbers[idx1] + numbers[idx2] > target)
        {
            --idx2;
        }
    }
    int *res = (int *)malloc(sizeof(int) * 2);
    res[0] = idx1 + 1;
    res[1] = idx2 + 1;
    *returnSize = 2;
    return res;
}
