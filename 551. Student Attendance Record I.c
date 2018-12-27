bool checkRecord(char* s) {
    int *pa=malloc(sizeof(int)*2);
    int i=0;
    for (i=0;i<2;i++){
        *(pa+i)=0;
    }
    i=0;
    while (*s!='\0'){
        if (*s=='A'){
            (*(pa+0))++;
        }else if (*s=='L'){
            if (*(s+1)=='L'&&*(s+2)=='L')
                (*(pa+1))++;
        }
        s++;
    }
    if (*(pa+0)>1||*(pa+1)>0){
        return 0;
    }else{
        return 1;
    }
}
