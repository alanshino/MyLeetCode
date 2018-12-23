int countSegments(char* s) {
    int sum=0;
    int slap=1;
    int i;
    int n=strlen(s);
    char *p=s;
    if (n!=0){
        for (i=0;i<n;i++){
            if (*(s+i)!=' '){
                slap=0;
                break;
            }
        }
        if (slap==1) return 0;
        if (*s==' ') sum=0;
        else sum++;
        while (*p!='\0'){
            if (*p==' '){
                slap=1;
            }else if (*p!=' '&&slap==1){
                sum++;
                slap=0;
            }
            p++;
        }
    }else{
        return 0;   
    }
    return sum;
}
