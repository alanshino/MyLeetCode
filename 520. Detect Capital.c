/* 520. Detect Capital */
/**
 * Given a word, you need to judge whether the usage of capitals in it is right or not.
 * We define the usage of capitals in a word to be right when one of the following cases holds:
 *
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * Example 1:
    Input: "USA"
    Output: True
 * Example 2:
    Input: "FlaG"
    Output: False
 * Example 3:
    Input: "Leetcode"
    Expected: true
 */

bool detectCapitalUse(char * word){
    if (*word >= 'A' && *word <= 'Z') { // 第一個大寫
        word++;
        if (*word < 'a') {              // 如果第二個小寫，後面都要小寫
            while (*word) {
                if (*word > 'Z') {
                    return 0;
                }
                word++;
            }
        } else {
            while (*word) {             // 否則都要大寫
                if (*word < 'a') {
                    return 0;
                }
                word++;
            }
        }
    } else {
        while (*word) {                // 全部小寫也為真
            if (*word < 'a') {
                return 0;
            }
            word++;
        }
    }
    return 1;
}

