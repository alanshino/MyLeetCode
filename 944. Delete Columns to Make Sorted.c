int minDeletionSize(char** A, int ASize) {
    int i=0,j=0,index=0;
    int k=strlen(*(A));
    for (i=0;i<k;i++){                          // 外行內列
        for (j=0;j<ASize-1;j++){                // 如果沒有遞增,代表上一個編碼大於下一個
            if (*(*(A+j)+i)>*(*(A+j+1)+i)){
                index++;                        // 修改數加一
                break;
            }
        }
    }
    return index;
}
