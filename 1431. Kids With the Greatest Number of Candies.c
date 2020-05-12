/* 1431. Kids With the Greatest Number of Candies */
/**
 * Given the array candies and the integer extraCandies, where candies[i] represents the number of candies that the ith kid has.
 * For each kid check if there is a way to distribute extraCandies among the kids such that
 * he or she can have the greatest number of candies among them.
 * Notice that multiple kids can have the greatest number of candies.
 *
 Example 1:
 * Input: candies = [2,3,5,1,3], extraCandies = 3
 * Output: [true,true,true,false,true]
  Explanation:
  Kid 1 has 2 candies and if he or she receives all extra candies (3) will have 5 candies --- the greatest number of candies among the kids.
  Kid 2 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids.
  Kid 3 has 5 candies and this is already the greatest number of candies among the kids.
  Kid 4 has 1 candy and even if he or she receives all extra candies will only have 4 candies.
  Kid 5 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids.
 *
 Example 2:
 * Input: candies = [4,2,1,1,2], extraCandies = 1
 * Output: [true,false,false,false,false]
 * Explanation: There is only 1 extra candy,
 * therefore only kid 1 will have the greatest number of candies among the kids regardless of who takes the extra candy.
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * Solution:
 * 這題很容易，首先找出分到最多糖果的人(max)。
 * 接著將每個人的糖果數量加上額外糖果數，如果大於(max)為真，反之為假。
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    bool *preturn = malloc(sizeof(bool) * candiesSize);
    int max = 0;
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > max)
            max = candies[i];
    }
    *returnSize = candiesSize;
    for (int i = 0; i < candiesSize; i++) {
        if ((candies[i] + extraCandies) >= max) {
            preturn[i] = 1;
        } else {
            preturn[i] = 0;
        }
    }
    return preturn;
}


/* faster */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * Solution:
   利用指標來走訪可以提高效率，原先需要對指標作加法(取值)。
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    bool *preturn = malloc(sizeof(bool) * candiesSize);
    bool *temp = preturn;
    int max = 0;
    for (int i = 0, *ptr_temp = candies; i < candiesSize; i++, ptr_temp++) {
        if (*ptr_temp > max)
            max = *ptr_temp;
    }
    *returnSize = candiesSize;
    for (int i = 0, *ptr_temp = candies; i < candiesSize; i++, ptr_temp++, temp++) {
        if ((*ptr_temp + extraCandies) >= max) {
            *temp = 1;
        } else {
            *temp = 0;
        }
    }

    return preturn;
}
