void rotate(int* nums, int numsSize, int k) {
    int temp,i=0,j=0;
    for (i=0;i<k;i++){                      // 記錄交換幾次
        temp=*(nums+numsSize-1);            // 紀錄最後一位的數值
        for (j=numsSize-1;j>=0;j--){        // 由最後開始走,避免使用到已放置更新的數值
            *(nums+j)=*(nums+j-1);          // 放置上一位的數值
        }
        *(nums)=temp;                       // 將第一個數值放入剛剛紀錄的最後一位數值
    }
    return ;
}

/** C faster
void rotate(int* nums, int numsSize, int k) {
    int n = k % numsSize;
    int *out;

    if (n == numsSize) {
        return;
    }
    if (n == 1) {
        int i;
        int last = nums[numsSize - 1];
        for (i = numsSize - 1; i >= 1; --i) {
            nums[i] = nums[i - 1];
        }
        nums[0] = last;
        return;
    }
    out = (int *)malloc(numsSize * sizeof(int));
    if (out != NULL) {
        int j = numsSize - n;
        int i;

        for (i = 0; i < n; ++i, ++j) {
            out[i] = nums[j];
        }
        for (j = 0; i < numsSize; ++i, ++j) {
            out[i] = nums[j];
        }
        for (i = 0; i < numsSize; ++i) {
            nums[i] = out[i];
        }
        free(out);
    } else {
        rotate(nums, numsSize, k - 1);
        rotate(nums, numsSize, 1);
    }
}
*/
