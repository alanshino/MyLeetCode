/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int *preturn = calloc(num_people, sizeof(int));               // 分配回傳 array , 個元素設置為 0
    int number = 1;                                               // 發配的糖果數目
    *returnSize = num_people;
    for (int i = 0; candies; i++) {
        if (candies - number >= 0) {                              // 現有糖果數如果大於即將分配的數目 (即可繼續分配)
            candies -= number;                                    // 現有糖果數減去分配糖果數
            preturn[i] += number++;
        }else {
            preturn[i] += candies;                                // 代表分完或是不夠分 , 將剩餘的全部給當前的元素
            return preturn;
        }
        if (i == num_people - 1)
            i = -1;                                               // loop 會 +1 所以指派為 -1
    }
    return preturn;
}




