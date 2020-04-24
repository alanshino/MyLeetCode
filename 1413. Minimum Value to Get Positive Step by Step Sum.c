/** 1413. Minimum Value to Get Positive Step by Step Sum **/

/**
 * Given an array of integers nums, you start with an initial positive value startValue.
 * In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).
 * Return the minimum positive value of startValue such that the step by step sum is never less than 1.
 */

/**
 * Input: nums = [-3,2,-3,4,2]
 * Output: 5
 * Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
                step by step sum
                startValue = 4 | startValue = 5 | nums
                  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
                  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
                  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
                  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
                  (4 +2 ) = 6  | (5 +2 ) = 7    |   2
 */

int minStartValue(int* nums, int numsSize){
    int min = 0;
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
        if (total < min) {
            min = total;
        }
    }

    if (min && min > 0)
        return min;
    else if (min < 0)
        return -min + 1;
    else
        return 1;
}


int minStartValue(int* nums, int numsSize)
{
    int i = 0,  min_sum = 0, sum = 0;

    while(i < numsSize) {
        sum += nums[i];
        if(sum < min_sum)
            min_sum = sum;
        i += 1;
    }

    return -1 * min_sum + 1;
}
