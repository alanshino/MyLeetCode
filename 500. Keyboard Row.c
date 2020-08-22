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
    char *row1 = "qwertyuiop";  // 第一列的字母集合
    char *row2 = "asdfghjkl";   // 第二列的字母集合
    char *row3 = "zxcvbnm";     // 第三列的字母集合
    char **word_temp = words;
    char **preturn;
    char temp;
    char valid = 1;             // 判斷是否符合題目條件
    char *valid_array = calloc(wordsSize, sizeof(char)); // 作為符合條件的集合(記錄住標位址)
    char table[26];                                      // 26個字母集合
    char total = 0;                                      // 符合條件的字串個數
    int step = 0;                                        // 指標偏移量
    char upper;                                          // 大寫字母處理
    // 紀錄各字母在鍵盤的列數
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
    // 比對該字串的所有字母是否都在同一列
    for (int i = 0; i < wordsSize; i++) {
        // 大小寫處理
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
            word_temp[i] -= step;  // 指標位址返回起始點
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
