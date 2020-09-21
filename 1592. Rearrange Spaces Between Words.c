/* 1592. Rearrange Spaces Between Words */
/**
 * You are given a string text of words that are placed among some number of spaces.
 * Each word consists of one or more lowercase English letters and are separated by at least one space.
 * It's guaranteed that text contains at least one word.
 * Rearrange the spaces so that there is an equal number of spaces between every pair of adjacent words and that number is maximized.
 * If you cannot redistribute all the spaces equally, place the extra spaces at the end,
 * meaning the returned string should be the same length as text.
 * Return the string after rearranging the spaces.
 *
 * Example 1:
    Input: text = "  this   is  a sentence "
    Output: "this   is   a   sentence"
    Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.
 * Example 2:
    Input: text = " practice   makes   perfect"
    Output: "practice   makes   perfect "
    Explanation: There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 extra space. We place this extra space at the end of the string.
 * Example 3:
    Input: text = "hello   world"
    Output: "hello   world"
 * Example 4:
    Input: text = "  walks  udp package   into  bar a"
    Output: "walks  udp  package  into  bar  a "
 * Example 5:
    Input: text = "a"
    Output: "a"
 */
char * reorderSpaces(char * text){
    char *temp = text;
    char *preturn = NULL;
    int space = 0;
    int word = 0;
    int str_len = 0;
    int average_space;
    while (*temp) {
        if (*temp == ' ') {
            space++;
            str_len++;
            temp++;
        } else {
            while (*temp != ' ' && *temp) {
                temp++;
                str_len++;
            }
            word++;
        }
    }
    if (word > 1) {
        average_space = space / (word - 1);
    } else {
        average_space = space / word;
    }
    preturn = malloc(sizeof(char) * (str_len + 1));
    temp = preturn;
    while (*text) {
        if (*text == ' ') {
            while (*text == ' ') {
                text++;
            }
        } else {
            while (*text != ' ' && *text) {
                *temp = *text;
                temp++;
                text++;
            }
            word--;
            if (word) {
                for (int i = 0; i < average_space; i++) {
                    *temp++ = ' ';
                }
                space -= average_space;
            }
        }
    }
    if (space) {
        while (space) {
            *temp++ = ' ';
            space--;
        }
    }
    *temp = '\0';
    return preturn;
}
