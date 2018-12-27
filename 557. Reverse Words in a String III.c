char* reverseWords(char* s) {
    int i=0,j=0,k=0;
    char c;
    char *ps=s;
    while (*ps!='\0'){
        if (*ps!=' '){
            i++;  //癘魁ǐ碭じ
            ps++;
        }else{
            ps-=i;
            for (j=0,k=i-1;j<i/2;j++,k--){  //秨﹍ユ传 ユ传Ω计i/2Ω
                c=*(ps+j);
                *(ps+j)=*(ps+k);
                *(ps+k)=c;
            }
            ps+=i+1;  // psǐЧ˙计,+1琌阁筁
            i=0;  //˙计衡
        }
    }
    ps-=i;
    for (j=0,k=i-1;j<i/2;j++,k--){ //瞒秨loop程传Ω
        c=*(ps+j);
        *(ps+j)=*(ps+k);
        *(ps+k)=c;
    }
    ps+=i+1;
    return s;
}
