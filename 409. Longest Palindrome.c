int longestPalindrome(char* s) {
    int a[26]={0};                          // �����j�p�g
    int b[26]={0};
    int i=0,palindrome=strlen(s),odd=0;     // �����^���,�Ω_��
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
            odd++;                         // �����X�ө_��
        }
        if (b[i]%2){
            odd++;
        }
    }
    if (odd){
        palindrome=palindrome-odd+1;       // �^��i�H�O�d�@�ө_�Ʀb����
        return palindrome;
    }else{
        return palindrome;
    }
}
