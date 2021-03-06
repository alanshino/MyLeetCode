int longestPalindrome(char* s) {
    int a[26]={0};                          // 紀錄大小寫
    int b[26]={0};
    int i=0,palindrome=strlen(s),odd=0;     // 紀錄回文數,及奇數
    while (*s){
        if (*s>='A'&&*s<='Z'){
            a[*s-'A']++;
        }else if (*s>='a'&&*s<='z'){
            b[*s-'a']++;
        }
        s++;
    }
    for (i=0;i<26;i++){
        if (a[i]%2){
            odd++;                         // 紀錄幾個奇數
        }
        if (b[i]%2){
            odd++;
        }
    }
    if (odd){
        palindrome=palindrome-odd+1;       // 回文可以保留一個奇數在中間
        return palindrome;
    }else{
        return palindrome;
    }
}
