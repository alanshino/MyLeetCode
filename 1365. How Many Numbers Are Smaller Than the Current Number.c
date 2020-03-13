/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 題目要求:
 * Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it.
 * That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
 * Return the answer in an array.
 * Example:
    Input: nums = [8,1,2,2,3]
    Output: [4,0,1,1,3]
    Explanation:
    For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).
    For nums[1]=1 does not exist any smaller number than it.
    For nums[2]=2 there exist one smaller number than it (1).
    For nums[3]=2 there exist one smaller number than it (1).
    For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
 * Example:
    Input: nums = [7,7,7,7]
    Output: [0,0,0,0]
 * 解題方式: 使用雙層迴圈逐步比較大小並記錄
 */

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int *preturn = malloc(sizeof(int) * numsSize);
    int counter = 0;                           // 計算比當前值還要小的數
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (i == j)                        // 比較數相同，直接跳過
                continue;
            else {
                if (nums[i] > nums[j])
                    counter++;
            }
        }
        preturn[i] = counter;
        counter = 0;
    }
    return preturn;
}

