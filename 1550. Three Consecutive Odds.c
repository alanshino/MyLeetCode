/* 1550. Three Consecutive Odds */
/**
 * Given an integer array arr, return true if there are three consecutive odd numbers in the array.
 * Otherwise, return false.
 * Example 1
 * Input: arr = [2,6,4,1]
 * Output: false
 * Explanation: There are no three consecutive odds.
 * Example 2
 * Input: arr = [1,2,34,3,4,5,7,23,12]
 * Output: true
 * Explanation: [5,7,23] are three consecutive odds.
 */

bool threeConsecutiveOdds(int* arr, int arrSize) {
    int three_true = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2) {
            three_true++;
        } else {
            three_true = 0;
        }
        if (three_true > 2)
            return 1;
    }
    return 0;
}

// faster
bool threeConsecutiveOdds(int* arr, int arrSize){
    int three_true = 0;
    int *ptr = arr;
    while (arrSize) {
        if (*ptr % 2) {
            three_true++;
        } else {
            three_true = 0;
        }
        if (three_true > 2)
            return 1;
        ptr++;
        arrSize--;
    }
    return 0;
}
