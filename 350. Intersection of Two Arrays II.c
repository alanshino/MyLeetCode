/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int Size=(nums1Size>nums2Size)?nums1Size:nums2Size;                        // ����̤j��,�γ̤p��
    int smaller=(nums1Size>nums2Size)?nums2Size:nums1Size;
    int *preturn=malloc(sizeof(int)*Size);                                     // ���t�̤j�Ŷ�
    int i,j;
    (*returnSize)=0;                                                           // ��l�^�Ǥj�p��0
    if (Size==nums2Size) {                                                     // �~�鬰�p��,���鬰�j��
        for (i=0;i<smaller;i++) {
            for (j=0;j<Size;j++) {
                if (*(nums1+i)==*(nums2+j)) {                                  // �p�G���ۦP�Ʀr,�N�ץ涰
                    *(preturn+(*returnSize))=*(nums1+i);                       // �^�ǪŶ��[1,�ñN�涰��J�^�ǪŶ�����
                    *(nums2+j)=-1;                                             // ��ƭȬ�-1,�קK���ƨ���
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
