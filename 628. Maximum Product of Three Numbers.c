//void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc (const void * a, const void * b);
int maximumProduct(int* nums, int numsSize){
    int Maximum_Product = 1;
    int negative = 0;
    qsort(nums, numsSize, sizeof(int), cmpfunc);              // 先對 array 做快速排序
    for (int i = 0; i < numsSize; i++) {
        negative++;                                           // 計算負數是否有兩個以上
        if (negative > 1)
            break;
    }
    if (negative == 2) {
        if (nums[0] * nums[1] * nums[numsSize - 1] > nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3]) // 如果兩個負數相乘後的結果較大
            return nums[0] * nums[1] * nums[numsSize - 1];                                                         // 就回傳這組答案
    }
    for (int i = numsSize - 1; i >= numsSize - 3; i--) {          // 因為快排過了 , 索引從最後面找三個相乘後回傳
        Maximum_Product *= nums[i];
        // printf("%d ",nums[i]);
    }
    return Maximum_Product;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


/** C

int maximumProduct(int* nums, int numsSize) {
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;
    int i;
    for(i=0; i< numsSize; i++)
    {
        if(nums[i] <= min1)
        {
            min2 = min1;
            min1 = nums[i];
        } else if (nums[i] > min1 && nums[i] < min2)
        {
            min2 = nums[i];
        }
        if(nums[i] >= max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        } else if (nums[i] >= max2)
        {
            max3 = max2;
            max2 = nums[i];
        } else if(nums[i] > max3)
        {
            max3 = nums[i];
        }
    }
    int val1 = min1 * min2 * max1;
    int val2 = max1 * max2 * max3;
    if(val1 > val2)
    {
        return val1;
    } else {
        return val2;
    }

}

*/

/** Java

class Solution {
    public int maximumProduct(int[] nums) {
        int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE, max3 = Integer.MIN_VALUE;
        int min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;
        for (int i : nums) {
            if (i > max3) {
                if (i > max2) {
                    max3 = max2;
                    if (i > max1) {
                        max2 = max1;
                        max1 = i;
                    } else {
                        max2 = i;
                    }
                } else {
                    max3 = i;
                }
            }
            if (i < min2) {
                if (i < min1) {
                    min2 = min1;
                    min1 = i;
                } else {
                    min2 = i;
                }
            }
        }
        return max1 * Math.max(min1 * min2, max2 * max3);
    }
}

*/
