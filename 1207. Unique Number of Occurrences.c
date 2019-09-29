void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc (const void * a, const void * b);

bool uniqueOccurrences(int* arr, int arrSize){
    int *punique = calloc(2002, sizeof(int));            // 依照題意範圍從 -1000 <= arr[i] <= 1000 因為 C 語言不支援負數索引
    for (int i = 0; i < arrSize; i++) {
        punique[arr[i] + 1000]++;                        // 所以所有索引直往上提 1000 , 避免負數索引
    }
    qsort(punique, 2002, sizeof(int), cmpfunc);          // 快速排序後保留剩下的元素
    /*for (int i = 0; i >= 0 && punique[i] != 0; i--) {
        printf("%d ", punique[i]);
    }  */
    /*for (int i = 0; i < 2002; i++) {
        if (punique[i] != 0)
            printf("%d ", i);
    }*/
    for (int i = 2001; i >= 0 && punique[i] != 0; i--) {
        if (punique[i] == punique[i - 1])                // 確定沒有任何相同值得元素 , 如果有相同回傳 0
            return 0;
    }
    return 1;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


/**
Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

*/
