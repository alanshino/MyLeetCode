bool rotateString(char* A, char* B) {
    int n1=strlen(A),i=0,last=0,j=0;
    int n2=strlen(B);
    char temp=0;
    char *pa=A,*pb=B;
    if (n1!=n2){                       // 字串長度不同,無法比較
        return 0;
    }
    if (*A=='\0'&&*B=='\0') return 1;  // 空字串為真
    for (i=0,last=n1-1;i<n1;i++){
        temp=*(pa+0);                  // 取得首位置的值
        for (j=0;j<last;j++){          // 後面位置依序向前排列
            *(pa+j)=*(pa+j+1);
        }
        *(pa+last)=temp;               // 最後一個為首字的值
        if (same(A,B)){                // 如果相同為真
            return 1;
        }else{
            continue;
        }
    }
    return 0;
}

int same(char *pa,char *pb){
    int i=0;
    while (*pa){
        if (*pa==*pb){                // 判斷是否相同
            pa++;
            pb++;
        }else{
            return 0;
        }
    }
    return 1;
}
