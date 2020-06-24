/* 1480. Running Sum of 1d Array */
/**
 * Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
 * Return the running sum of nums.
 * Example 1
 * Input: nums = [1,2,3,4]
 * Output: [1,3,6,10]
 * Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
 * Example 2
 * Input: nums = [1,1,1,1,1]
 * Output: [1,2,3,4,5]
 * Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
 * Solution
 * 每次都記錄上一次運算的值，並將其與當前運算值相加。
 */

int* runningSum(int* nums, int numsSize, int* returnSize){
    int *preturn = malloc(sizeof(int) * numsSize);
    int *ptr_temp = nums;
    int *ptr_return = preturn;
    int temp = 0;
    *returnSize = numsSize;
    while (numsSize) {
        *ptr_return = *ptr_temp + temp;
        temp = *ptr_return;
        numsSize--;
        ptr_return++;
        ptr_temp++;
    }
    return preturn;
}
