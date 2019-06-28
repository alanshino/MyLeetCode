void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc (const void * a, const void * b);
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for (int i = m, j = 0; i < m + n; i++, j++) {                         // nums1Size 一定 > nums2Size
        *(nums1 + i) = *(nums2 + j);                                      // 從 nums1Size 的結尾 m 開始放入 nums2 的元素
    }
    /*for (int i = 0; i < m + n; i++)
        printf("%d ",*(nums1 + i));
    */
    qsort(nums1, m + n, sizeof(int), cmpfunc);                            // 最後呼叫快排
    return;
}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


