/**
  * Given two arrays of integers nums and index. Your task is to create target array under the following rules:

    Initially target array is empty.
    From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
    Repeat the previous step until there are no elements to read in nums and index.
    Return the target array.

    It is guaranteed that the insertion operations will be valid.

  * Example 1:
        Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
        Output: [0,4,1,3,2]
        Explanation:
        nums       index     target
        0            0        [0]
        1            1        [0,1]
        2            2        [0,1,2]
        3            2        [0,1,3,2]
        4            1        [0,4,1,3,2]
  * Example 2:
        Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
        Output: [0,1,2,3,4]
        Explanation:
        nums       index     target
        1            0        [1]
        2            1        [1,2]
        3            2        [1,2,3]
        4            3        [1,2,3,4]
        0            0        [0,1,2,3,4]

    題目給定兩個陣列，並要求我們按照 index 裡的擺放順序排列
    讓回傳陣列擁有 nums 的元素以及 index 要求的順序，最後將新分配的陣列回傳。
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int *preturn = malloc(sizeof(int) * numsSize);
    int counter = 0;                                // 用來記錄需要往後移動的元素個數
    *returnSize =  numsSize;
    for (int i = 0; i < numsSize; i++) {            // 先將陣列初始為 -1 ，以便用來記錄是否已經放入新的元素
        preturn[i] = -1;
    }
    for (int i = 0; i < numsSize; i++) {
        if (preturn[index[i]] == -1) {              // 代表未有舊值，直接放入即可
            preturn[index[i]] = nums[i];
        } else {
            for (int j = index[i]; j < numsSize; j++) {  // 計算需移動的舊值個數
                if (preturn[j] != -1)
                    counter++;
            }

            for (int j = index[i] + counter, k = 0; k < counter; k++, j--) {
                preturn[j] = preturn[j - 1];
            }
            preturn[index[i]] = nums[i];
            counter = 0;
        }
    }
    return preturn;
}


