/* 1464. Maximum Product of Two Elements in an Array */
/**
 * Given the array of integers nums, you will choose two different indices i and j of that array.
 * Return the maximum value of (nums[i]-1)*(nums[j]-1).
 * ---------------------------------------------------------------------------------------------
 * Example 1:
    Input: nums = [3,4,5,2]
    Output: 12
    Explanation: If you choose the indices i=1 and j=2 (indexed from 0),
    you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12.
 * ---------------------------------------------------------------------------------------------
 * Example 2:
    Input: nums = [1,5,4,5]
    Output: 16
    Explanation: Choosing the indices i=1 and j=3 (indexed from 0),
    you will get the maximum value of (5-1)*(5-1) = 16.
 * ---------------------------------------------------------------------------------------------
 * Example 3:
    Input: nums = [3,7]
    Output: 12
 * ---------------------------------------------------------------------------------------------
 * Solution
   題目很簡單，只須找出最大的兩個不相同數，並回傳其減1後相乘的結果即可。
 */

int maxProduct(int* nums, int numsSize){
    int max1[2] = {0}, max2 = 0;          // 分別保存兩個最大的數
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max1[0]) {
            max1[0] = nums[i];
            max1[1] = i;
        }
    }

    nums[max1[1]] = 0;                   // 紀錄第一個最大數，為避免再次找到，所以記下其註標並消除該數值
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max2) {
            max2 = nums[i];
        }
    }
    return (max1[0] - 1) * (max2 - 1);
}

/*         faster             */
/**
 *  用一個指標來做移動，消除原先的取址時間來加快城市運行的速度。
 */
int maxProduct(int* nums, int numsSize){
    int max1 = 0, max2 = 0, pos;
    int *ptr = nums, i;              // 暫存指標
    for (int i = 0; i < numsSize; i++, ptr++) {
        if (*ptr > max1) {
            max1 = *ptr;
            pos = i;
        }
    }
    ptr = nums;
    nums[pos] = 0;
    for (int i = 0; i < numsSize; i++, ptr++) {
        if (*ptr > max2) {
            max2 = *ptr;
        }
    }
    return (max1 - 1) * (max2 - 1);
}
