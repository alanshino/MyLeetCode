/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int Size=(nums1Size>nums2Size)?nums1Size:nums2Size;                        // 先找最大值,及最小值
    int smaller=(nums1Size>nums2Size)?nums2Size:nums1Size;
    int *preturn=malloc(sizeof(int)*Size);                                     // 分配最大空間
    int i,j;
    (*returnSize)=0;                                                           // 初始回傳大小為0
    if (Size==nums2Size) {                                                     // 外圈為小值,內圈為大值
        for (i=0;i<smaller;i++) {
            for (j=0;j<Size;j++) {
                if (*(nums1+i)==*(nums2+j)) {                                  // 如果找到相同數字,意謂交集
                    *(preturn+(*returnSize))=*(nums1+i);                       // 回傳空間加1,並將交集放入回傳空間之中
                    *(nums2+j)=-1;                                             // 改數值為-1,避免重複取數
                    (*returnSize)++;
                    break;
                }
            }
        }
    }else {
        for (i=0;i<smaller;i++) {
            for (j=0;j<Size;j++) {
                if (*(nums2+i)==*(nums1+j)) {
                    *(preturn+(*returnSize))=*(nums2+i);
                    *(nums1+j)=-1;
                    (*returnSize)++;
                    break;
                }
            }
        }
    }
    return preturn;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/** C faster
int comparator(const void *a, const void *b) {
    return  *(int *) a > *(int *) b;
}


int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), comparator);
    qsort(nums2, nums2Size, sizeof(int), comparator);
    *returnSize = 0;
    int *res = malloc(nums1Size * sizeof(int));
    for (int i = 0, j = 0; i < nums1Size && j < nums2Size; ) {
        if (nums1[i] == nums2[j]) {
            res[(*returnSize)++] = nums1[i];
            i++, j++;
        }
        else if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
    return realloc(res, *returnSize * sizeof(int));
}
*/
