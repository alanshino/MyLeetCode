/**
 * problem 1502. Can Make Arithmetic Progression From Sequence
 * Given an array of numbers arr. A sequence of numbers is called an arithmetic progression
 * if the difference between any two consecutive elements is the same.
 * Return true if the array can be rearranged to form an arithmetic progression, otherwise, return false.
 * Example 1:
   Input: arr = [3,5,1]
   Output: true
   Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
 * Example 2:
   Input: arr = [1,2,4]
   Output: false
   Explanation: There is no way to reorder the elements to obtain an arithmetic progression.
 * Solution:
   先對陣列做快速排序，找到前兩個數值的差，用這個差值依序走訪陣列。
   能夠走完表示元素是等差排列，不能則否。
*/
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

bool canMakeArithmeticProgression(int* arr, int arrSize){
    int diff = 0;
    qsort(arr, arrSize, sizeof(int), cmpfunc);
    diff = arr[1] - arr[0];                          // 找出差值
    for (int i = 1, j = 0; i < arrSize; i++, j++) {  // 走訪陣列
        if (arr[j] + diff == arr[i]) {
            ;
        } else {
            return 0;
        }
    }
    return 1;
}
