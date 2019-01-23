bool buddyStrings(char* A, char* B) {
    int lengha=strlen(A);
    int lenghb=strlen(B);
    int a[26]={0};                     // 紀錄字元
    int x[3]={0},temp,i,y;             // 放置需要換置的字元的index
    if (lengha!=lenghb) return 0;      // 長度不同,return 0
    for (i=0,y=0;i<lengha;i++){
        if (*(A+i)!=*(B+i)){           // 如果有不相同的字元,放入x array
            x[y]=i;
            y++;
            if (y>2){                  // 如果超過三個字直接return 0
                return 0;
            }
        }
        a[*(A+i)-97]++;                // 紀錄每個字的出現次數
    }
    if (y==0){                         // 如果沒有不相同的字,但有連續出現的字為真,反之為假
        for (i=0;i<26;i++){
            if (!(a[i]%2)&&a[i]!=0){
                return 1;
            }
        }
        return 0;
    }else{                             // 互換兩個不同的字元
        temp=*(A+x[0]);
        *(A+x[0])=*(A+x[1]);
        *(A+x[1])=temp;
        if (same(A,B)){                // 比較換完後是否相同
            return 1;
        }else{
            return 0;
        }
    }
}

int same(char *A,char *B){             // call function 判斷是否相同
    while (*A&&*B){
        if (*A!=*B) return 0;
        A++;
        B++;
    }
    return 1;
}
