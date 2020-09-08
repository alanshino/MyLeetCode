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
    int count = 0;           // �p��r����
    int point = 0;           // �p��p���I��
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
    point = count / 3;      // ��X�ݭn���p���I�ơA�J��3�����Ʒ|�h�@��
    preturn = malloc(sizeof(char) * (point + count + 1));
    preturn[point + count] = 0;
    for (int i = point + count - 1, j = 0; i >= 0; i--, j++) {
        if (!(j % 3) && j != 0) {      // ��X�w��p���I����}
            preturn[i] = '.';
            j = -1;
        } else {
            preturn[i] = temp % 10 + '0'; // ��l�����ɤW�r���Y�i
            temp /= 10;
        }
    }
    if (*preturn == '.') {  // ���r���p���I��ܦh�@�Ӥp���I�A�������ʫ��Ц�}
        preturn++;
    }
    return preturn;
}
