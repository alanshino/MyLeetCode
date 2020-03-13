/**
 * Given an integer n,
 * return a string with n characters such that each character in such string occurs an odd number of times.
 * The returned string must contain only lowercase English letters. If there are multiples valid strings, return any of them.
 * Example:
    Input: n = 4
    Output: "pppz"
    Explanation: "pppz" is a valid string since the character 'p' occurs three times and the character 'z' occurs once.
    Note that there are many other valid strings such as "ohhh" and "love".
 * Example:
    Input: n = 2
    Output: "xy"
    Explanation: "xy" is a valid string since the characters 'x' and 'y' occur once.
    Note that there are many other valid strings such as "ag" and "ur".
 * 解題方式: 題目指要求回傳奇數的字元形式，並未限制使用的字元。
             把題目拆成兩個判斷來作，偶數-1必得到兩個奇數。
             其中一個塞入任意字元，另一個塞入不相同字元即可
 */

char * generateTheString(int n){
    char *preturn = malloc(sizeof(char) * n + 1);   // 要記得保留'\0'的空間
    int i = 0;
    if (n % 2) {
        for (i = 0; i < n; i++) {
            preturn[i] = 'a';                // 以'a'來作(可自由替換)
        }
    }else {
        for (i = 0; i < n - 1; i++) {
            preturn[i] = 'a';
        }
        preturn[i++] = 'b';                 // 任意填補的字元，只要不相同即可
    }
    preturn[i] = '\0';
    return preturn;
}


