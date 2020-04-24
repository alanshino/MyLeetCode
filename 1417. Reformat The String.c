/** 1417. Reformat The String **/

/**
 * Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
 * You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit.
 * That is, no two adjacent characters have the same type.
 * Return the reformatted string or return an empty string if it is impossible to reformat the string.
 */
/** Example 1
 * Input: s = "a0b1c2"
 * Output: "0a1b2c"
 * Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
 ** Example 2
 * Input: s = "1229857369"
 * Output: ""
 * Explanation: "1229857369" has only digits so we cannot separate them by characters.
 */

/** Solution
 * ���t��Ӱ}�C�Ӥ��O�O�s�Ʀr��r���A�A�ӭ��s�ƦC��^�ǡC
 * �z�Ѹ����e���A������ɶ���O����ϥε��G�����t�C
 */
char * reformat(char * s){
    char *temp = s;
    char *temp1 = NULL;
    char *temp2 = NULL;
    char *preturn = NULL;
    int digit = 0;
    int alpha = 0;
    int i, j;
    while (*temp) {
        if (*temp >= '0' && *temp <= '9') {
            digit++;
        }
        if (*temp >= 'a' && *temp <= 'z') {
            alpha++;
        }
        temp++;
    }
    if (!digit && alpha > 1)
        return "";
    if (digit > 1 && !alpha)
        return "";
    if (digit - 2 > alpha || alpha - 2 > digit)
        return "";
    temp1 = malloc(sizeof(char) * (digit + 1));
    temp2 = malloc(sizeof(char) * (alpha + 1));
    temp = s;
    temp1[digit] = '\0';
    temp2[alpha] = '\0';
    i = digit;
    j = alpha;
    while (*temp) {
        if (*temp >= '0' && *temp <= '9') {
            temp1[--digit] = *temp;
        } else if (*temp >= 'a' && *temp <= 'z') {
            temp2[--alpha] = *temp;
        }
        temp++;
    }
    digit = i;
    alpha = j;
    preturn = malloc(sizeof(char) * (digit + alpha + 1));

    if (digit > alpha) {                          // �Ʀr��r���h�A�N��ƧǮɼƦr�]�r���C
        for (i = 0, j = 0; i < alpha; i++) {
            preturn[j++] = temp1[i];
            preturn[j++] = temp2[i];
        }
        preturn[j++] = temp1[i];
        preturn[j] = '\0';
        return preturn;
    } else if (alpha > digit) {                  // �r����Ʀr�h�A�N��ƧǮɦr���]�Ʀr�C
        for (i = 0, j = 0; i < digit; i++) {
            preturn[j++] = temp2[i];
            preturn[j++] = temp1[i];
        }
        preturn[j++] = temp2[i];
        preturn[j] = '\0';
        return preturn;
    } else {                                      // �@�˦h�N�H���ƦC�C
        for (i = 0, j = 0; i < digit; i++) {
            preturn[j++] = temp2[i];
            preturn[j++] = temp1[i];
        }
        preturn[j] = '\0';
        return preturn;
    }
}
