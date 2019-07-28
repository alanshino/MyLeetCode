/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc (const void * a, const void * b);
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int *preturn = malloc(sizeof(int) * arr1Size);
    int start = 0;
    int count = 0;
    *returnSize = arr1Size;
    for (int i = 0; i < arr2Size; i++) {                    // arr2 包含題目要求的排列順序 , 所以放在外圈
        for (int j = 0; j < arr1Size; j++) {                // 逐敘走訪 arr1 , 查找相同的元素已重新排序
            if (arr1[j] == -1)
                continue;
            if (arr1[j] == arr2[i]) {
                preturn[count] = arr1[j];
                arr1[j] = -1;                               // 排序完的元素設置為 -1
                count++;
            }
        }
    }
    qsort(arr1, arr1Size, sizeof(int), cmpfunc);            // 進行快速排序
  /*  for (int i = 0; i < arr1Size, count < arr1Size; i++) {// 原本以為是按照原先元素的位置直接排列
        if (arr1[i] != -1) {
            preturn[count] = arr1[i];
            arr1[i] = -1;
            count++;
        }
    } */
    for (int i = count; i < arr1Size; i++) {                // 直接將快速排序完後剩餘的元素 , 放入回傳 array
        preturn[count++] = arr1[i];
    }
    /** 為測試元素用 , 註解掉後速度會提升一倍
    for (int i = 0; i < arr1Size; i++) {
        printf("%d ",preturn[i]);
    }
    */
    return preturn;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
