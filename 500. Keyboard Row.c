/* 500. Keyboard Row */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 * Given a List of words,
 * return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
 * Example 1
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * Example 2
 * ["Aasdfghjkl","Qwertyuiop","zZxcvbnm"]
 */
int string_len(char *p);
char ** findWords(char ** words, int wordsSize, int* returnSize){
    char *row1 = "qwertyuiop";  // �Ĥ@�C���r�����X
    char *row2 = "asdfghjkl";   // �ĤG�C���r�����X
    char *row3 = "zxcvbnm";     // �ĤT�C���r�����X
    char **word_temp = words;
    char **preturn;
    char temp;
    char valid = 1;             // �P�_�O�_�ŦX�D�ر���
    char *valid_array = calloc(wordsSize, sizeof(char)); // �@���ŦX���󪺶��X(�O����Ц�})
    char table[26];                                      // 26�Ӧr�����X
    char total = 0;                                      // �ŦX���󪺦r��Ӽ�
    int step = 0;                                        // ���а����q
    char upper;                                          // �j�g�r���B�z
    // �����U�r���b��L���C��
    while (*row1) {
        table[*row1 - 97] = 1;
        row1++;
    }
    while (*row2) {
        table[*row2 - 97] = 2;
        row2++;
    }
    while (*row3) {
        table[*row3 - 97] = 3;
        row3++;
    }
    /*
    for (int i = 0; i < 26; i++) {
        printf("%d", table[i]);

    }
    */
    // ���Ӧr�ꪺ�Ҧ��r���O�_���b�P�@�C
    for (int i = 0; i < wordsSize; i++) {
        // �j�p�g�B�z
        if (*word_temp[i] >= 'A' && *word_temp[i] <= 'Z') {
            upper = *word_temp[i] + 32;
            temp = table[upper - 97];
        } else {
            temp = table[*word_temp[i] - 97];
        }
        while (*word_temp[i]) {
            if (*word_temp[i] >= 'A' && *word_temp[i] <= 'Z') {
                upper = *word_temp[i] + 32;
                if (temp != table[upper - 97]) {
                    valid = 0;
                    break;
                } else {
                    temp = table[upper - 97];
                    word_temp[i]++;
                    step++;
                    // printf("%s %d\n", word_temp[i], step);
                }
            } else {
                if (temp != table[*word_temp[i] - 97]) {
                    valid = 0;
                    break;
                } else {
                    temp = table[*word_temp[i] - 97];
                    word_temp[i]++;
                    step++;
                    // printf("%s %d\n", word_temp[i], step);
                }
            }
        }
        if (valid) {
            valid_array[i] = 1;
            word_temp[i] -= step;  // ���Ц�}��^�_�l�I
        } else {
            valid_array[i] = 0;
        }
        step = 0;
        valid = 1;
    }
    for (int i = 0; i < wordsSize; i++) {
        if (valid_array[i])
            total++;
    }
    // printf("%d", total);
    *returnSize = total;
    preturn = malloc(sizeof(char *) * total);
    for (int i = 0, j = 0; i < wordsSize; i++) {
        if (valid_array[i]) {
            // preturn[j] = word_temp[i];
            total = string_len(word_temp[i]) + 1;
            preturn[j] = malloc(sizeof(char) * total);
            for (int k = 0; k < total - 1; k++) {
                preturn[j][k] = *word_temp[i]++;
            }
            preturn[j][total - 1] = 0;
            //printf("%s\n", preturn[j]);
            j++;
        }
    }
    return preturn;
}

int string_len(char *p)
{
    int count = 0;
    while (*p) {
        p++;
        count++;
    }
    return count;
}
