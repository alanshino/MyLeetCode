/* 1576. Replace All ?'s to Avoid Consecutive Repeating Characters */
/**
 * Given a string s containing only lower case English letters and the '?' character,
 * convert all the '?' characters into lower case letters such that the final string does not contain any consecutive repeating characters.
 * You cannot modify the non '?' characters.
 * It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.
 * Return the final string after all the conversions (possibly zero) have been made.
 * If there is more than one solution, return any of them.
 * It can be shown that an answer is always possible with the given constraints.
 *
 * Example 1:
    Input: s = "?zs"
    Output: "azs"
    Explanation: There are 25 solutions for this problem. From "azs" to "yzs", all are valid.
    Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".
 * Example 2:
    Input: s = "ubv?w"
    Output: "ubvaw"
    Explanation: There are 24 solutions for this problem.
    Only "v" and "w" are invalid modifications as the strings will consist of consecutive repeating characters in "ubvvw" and "ubvww".
 * Example 3:
    Input: "????????????????????????????????????????????????????????????????????????????????????????????????????"
    Expected: "acacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacacac"
 */

char * modifyString(char * s){
    int strlen_s = strlen(s);
    char ascii = 97;
    if (strlen_s == 1 && s[0] == '?') {
        return "a";
    }
    for (int i = 0; i < strlen_s; i++) {
        if (s[i] == '?') {
            if (!i) {
                if (s[i + 1] == '?') {
                    s[i] = 'a';
                } else if (s[i + 1] == 'z') {
                    s[i] = s[i + 1] - 1;
                } else {
                    s[i] = s[i + 1] + 1;
                }
            } else if (i == (strlen_s - 1)) {
                if (s[i - 1] == 'z') {
                    s[i] = s[i - 1] - 1;
                } else {
                    s[i] = s[i - 1] + 1;
                }
            } else {
                while (ascii < 123) {
                    if (ascii == s[i - 1] || ascii == s[i + 1 ]) {
                        ascii++;
                    } else {
                        s[i] = ascii;
                        break;
                    }
                }
                ascii = 97;
            }
        }
    }
    return s;
}
