/*  412. Fizz Buzz  */
/**
 * Write a program that outputs the string representation of numbers from 1 to n.
 * But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”.
 * For numbers which are multiples of both three and five output “FizzBuzz”.
 * Example:
    n = 15,
    Return:
    [
        "1",
        "2",
        "Fizz",
        "4",
        "Buzz",
        "Fizz",
        "7",
        "8",
        "Fizz",
        "Buzz",
        "11",
        "Fizz",
        "13",
        "14",
        "FizzBuzz"
    ]
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char *fizz = "Fizz";
char *buzz = "Buzz";
char *fizzbuzz = "FizzBuzz";             // 題目指定之回傳字串
char ** fizzBuzz(int n, int* returnSize){
    int temp;
    int number_count = 0;
    char **preturn = malloc(sizeof(char *) * n);
    *returnSize = n;
    for (int i = 0, j = i + 1; i < n; i++, j++) {
        if (!(j % 3) && !(j % 5)) {
            preturn[i] = fizzbuzz;
        } else if (!(j % 3)) {
            preturn[i] = fizz;
        } else if (!(j % 5)) {
            preturn[i] = buzz;
        } else {
            temp = j;
            while (temp) {
                number_count++;
                temp /= 10;
            }
            preturn[i] = malloc(sizeof(char) * (number_count + 1));
            temp = j;
            preturn[i][number_count] = 0;
            for (int k = number_count - 1; k >= 0; k--) {   // 依序放置數字(ascii)
                preturn[i][k] = temp % 10 + 48;
                temp /= 10;
            }
            number_count = 0;
        }
    }
    return preturn;
}
