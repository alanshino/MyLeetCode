int longestPalindrome(char* s) {
    int a[26]={0};                          // 魁糶
    int b[26]={0};
    int i=0,palindrome=strlen(s),odd=0;     // 魁ゅ计,の计
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
            odd++;                         // 魁碭计
        }
        if (b[i]%2){
            odd++;
        }
    }
    if (odd){
        palindrome=palindrome-odd+1;       // ゅ玂痙计い丁
        return palindrome;
    }else{
        return palindrome;
    }
}
