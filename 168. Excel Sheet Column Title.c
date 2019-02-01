char* convertToTitle(int n) {
    int total=0,n1=n,status=0,i=0;
    char *preturn=NULL,*pc=NULL;
    while (n1>0){                                       // 判斷需要幾個空間的大小
        n1/=26;
        total++;
    }
    preturn=malloc(sizeof(char)*(total+1));
    pc=malloc(sizeof(char)*(total+1));
    while (n>0){
        status=n%26;
        n/=26;
        if (!status){
            *(preturn+i)='Z';                          // 遇到 Z 因為進位而需要減 1
            i++;
            n--;
        }else{
            *(preturn+i)=status+'@';                   // 'A' is 1 , ASCII '@' is 'A' - 1
            i++;
        }
    }
    *(preturn+i)='\0';
    //printf("%s\n",preturn);
    for (i=total-1,n1=0;i>=0;i--,n1++){
        if (*(preturn+i)>='A'&&*(preturn+i)<='Z'){     // 將字串倒置
            *(pc+n1)=*(preturn+i);
        }
        else{
            n1--;                                      // 遇到非大寫字元,需要先將移動改變放入值,但寫入區間不能變動,所以減 1 保持原值
            continue;
        }
    }
    *(pc+n1)='\0';
    free(preturn);                                     // 釋放轉至前的字串
    return pc;
}
