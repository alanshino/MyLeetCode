char findTheDifference(char* s, char* t) {
    int a[26]={0};
    int b[26]={0};
    while (*s){
        a[*s-97]++;               // 依ascii碼放進array
        s++;
    }
    while (*t){
        b[*t-97]++;               // 依ascii碼放進array
        t++;
    }
    for (int i=0;i<26;i++){
        if (a[i]!=b[i]){          // 走完array找到對應值不同的那個索引位置
            return i+97;
        }
    }
    return 0;
}
