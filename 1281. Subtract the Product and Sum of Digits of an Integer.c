int subtractProductAndSum(int n){
    int temp = n;
    int i = 1, j = 0;
    while (n) {                   // 找出相乘
        i *= n % 10;
        n /= 10;
    }
  //  printf("%d ", i);
    while (temp) {                // 找出相加
        j += temp % 10;
        temp /= 10;
    }
  //  printf("%d ", j);
    return i - j;
}

/**
 *  這題非常容易，只須按照範例逐步完成即可
 *  Example 1:
 *  Input: n = 234
 *  Output: 15
 *  Explanation:
 *  Product of digits = 2 * 3 * 4 = 24
 *  Sum of digits = 2 + 3 + 4 = 9
 *  Result = 24 - 9 = 15
 *
 *  Example 2:
 *  Input: n = 4421
 *  Output: 21
 *  Explanation:
 *  Product of digits = 4 * 4 * 2 * 1 = 32
 *  Sum of digits = 4 + 4 + 2 + 1 = 11
 *  Result = 32 - 11 = 21
 *  Given an integer number n, return the difference between the product of its digits and the sum of its digits.
 */
