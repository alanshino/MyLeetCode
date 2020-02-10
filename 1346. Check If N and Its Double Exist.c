/**
Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :

    i != j
    0 <= i, j < arr.length
    arr[i] == 2 * arr[j]

題目給定整數陣列arr，請檢查是否存在兩個整數N和M，以使N為M的兩倍（即N = 2 * M）。

Example :
Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.

Input: arr = [7,1,14,11]
Output: true
Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.

Input: arr = [3,1,7,11]
Output: false
Explanation: In this case does not exist N and M, such that N = 2 * M.
*/


bool checkIfExist(int* arr, int arrSize){

    for (int i = 0; i < arrSize; i++) {              // 使用巢狀loop來判定
        for (int j = 0; j < arrSize; j++) {
            if (i == j) continue;                    // 跳過相同索引
            if (arr[j] * 2 == arr[i]) return 1;      // 如果找到單一元素的double符合條件救回傳TRUE
        }
    }

    return 0;
}
