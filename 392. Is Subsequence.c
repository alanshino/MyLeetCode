bool isSubsequence(char * s, char * t){
    int num_s = strlen(s);               // s 是子字串 , 計算出其長度
    int count = 0;                       // 用來判斷相符字元的數目
    while (*t) {
        if (*s == *t) {                  // 如果 *s 的字元與 *t 相等
            count++;
            s++;                         // s 指標移動
        }
        t++;                             // t 指標無論是否相等皆會移動
    }
    if (count == num_s)
        return 1;
    else
        return 0;
}

/**

bool isSubsequence(char * s, char * t){
    while (*t) {
        if (*s == *t) {
            s++;
        }
        t++;
    }
    if (*s == '\0')
        return 1;
    else
        return 0;
}

*/
