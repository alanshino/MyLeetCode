char findTheDifference(char* s, char* t) {
    int a[26]={0};
    int b[26]={0};
    while (*s){
        a[*s-97]++;               // ��ascii�X��iarray
        s++;
    }
    while (*t){
        b[*t-97]++;               // ��ascii�X��iarray
        t++;
    }
    for (int i=0;i<26;i++){
        if (a[i]!=b[i]){          // ����array�������Ȥ��P�����ӯ��ަ�m
            return i+97;
        }
    }
    return 0;
}
