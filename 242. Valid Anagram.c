bool isAnagram(char* s, char* t) {
    int a[26]={0},i=0,b[26]={0}; //兩兩相加,相同必為偶數
    if (*s=='\0'&&*t=='\0') return 1;
    while (*s!='\0'){
        a[*s-97]++;
        s++;
    }
    while (*t!='\0'){
        b[*t-97]++;
        t++;
    }
    for (i=0;i<26;i++){
        if (a[i]==b[i]){
            continue;
        }else
            return 0;
    }
    return 1;
}
