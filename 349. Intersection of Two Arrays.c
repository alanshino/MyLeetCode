/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int i=0,j=0,min,k,same=1;
    int total=0;
    int *preturn=NULL;
    *returnSize=(nums1Size>nums2Size)?nums1Size:nums2Size;              // �������t�̤j�Ŷ�
    preturn=malloc(sizeof(int)**returnSize);
    for (i=0;i<*returnSize;i++){
        *(preturn+i)=-1;
    }
    if (nums1Size>nums2Size){                                           // �Ѥp��j
        for (i=0;i<nums2Size;i++){
            for (j=0;j<nums1Size;j++){
                if (*(nums2+i)==*(nums1+j)){                            // �p�G���۵���,same=1
                    same=1;
                    for (k=0;k<=total;k++){                             // �p�G�^�ǦC���w�g�X�{�ۦP�Ʀr,same=0
                        if (*(nums1+j)==*(preturn+k)){
                            same=0;
                            break;
                        }
                    }
                    if (same){
                        *(preturn+total)=*(nums1+j);
                        total++;                                        // total �������X�ӥ涰
                        break;
                    }
                }
            }
        }
    }else{
        for (i=0;i<nums1Size;i++){
            for (j=0;j<nums2Size;j++){
                if (*(nums1+i)==*(nums2+j)){
                    same=1;
                    for (k=0;k<=total;k++){
                        if (*(nums2+j)==*(preturn+k)){
                            same=0;
                            break;
                        }
                    }
                    if (same){
                        *(preturn+total)=*(nums2+j);
                        total++;
                        break;
                    }
                }
            }
        }
    }
    *returnSize=total;
    return preturn;
}

/**                                                        // the faster
int cmp(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {


    qsort(nums1,nums1Size,sizeof(int),cmp);
    qsort(nums2,nums2Size,sizeof(int),cmp);

    int i = 0;
    int j = 0;
    int k = 0;
    for(i=0;i<nums1Size;i++)
    {
        if(k&&nums1[k-1]==nums1[i])
        {
            continue;
        }
        while(j<nums2Size&&nums2[j]<nums1[i])
        {
            j++;
        }
        if(j==nums2Size)
        {
            break;
        }
        if(nums2[j]==nums1[i])
        {
            nums1[k++]=nums1[i];
        }
    }
    *returnSize = k;
    return nums1;
}
*/
