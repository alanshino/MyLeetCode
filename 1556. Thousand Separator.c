/* 1556. Thousand Separator */
/**
 * Given an integer n, add a dot (".") as the thousands separator and return it in string format.
 * Example 1:
    Input: n = 987
    Output: "987"
 * Example 2:
    Input: n = 1234
    Output: "1.234"
 * Example 3:
    Input: n = 123456789
    Output: "123.456.789"
 * Example 4:
    Input: n = 0
    Output: "0"
 */

char * thousandSeparator(int n){
    int count = 0;           // 璸衡じ计
    int point = 0;           // 璸衡计翴计
    int temp = n;
    char *preturn = NULL;
    if (!n) {
        return "0";
    }
    while (temp) {
        count++;
        temp /= 10;
    }
    temp = n;
    point = count / 3;      // 衡惠璶计翴计笿3计穦
    preturn = malloc(sizeof(char) * (point + count + 1));
    preturn[point + count] = 0;
    for (int i = point + count - 1, j = 0; i >= 0; i--, j++) {
        if (!(j % 3) && j != 0) {      // т计翴
            preturn[i] = '.';
            j = -1;
        } else {
            preturn[i] = temp % 10 + '0'; // ㄤ緇钡干じ
            temp /= 10;
        }
    }
    if (*preturn == '.') {  // 计翴ボ计翴钡簿笆夹
        preturn++;
    }
    return preturn;
}
