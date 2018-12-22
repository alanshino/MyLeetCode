char* reverseString(char* s) {
    int n=strlen(s);
    int i,j;
    char c;
    for (i=0,j=n-1;i<n/2;i++,j--){
        c=*(s+i);
        *(s+i)=*(s+j);
        *(s+j)=c;
    }
    return s;
}
