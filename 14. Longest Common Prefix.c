char* longestCommonPrefix(char** strs, int strsSize) {
    int small=2147483647,i,temp=0,index=0,check=1,j,count=0;
    char *preturn=NULL;
    if (!strsSize)                             // 空字串,或只有一組
        return "";
    else if (strsSize==1)
        return *strs;
    for (i=0;i<strsSize;i++){                  // 找出最小字串,以及其索引值
        if ((temp=strlen(*(strs+i)))<small){
            small=temp;
            index=i;
        }
    }
    preturn=malloc(sizeof(char)*(small+1));
    for (i=0;i<small;i++){
        for (j=0;j<strsSize;j++){
            if (j==index)
                continue;
            if (*(*(strs+j)+i)==*(*(strs+index)+i))    // 跟最小項比對,相等的存入
                continue;
            else{
                if (i==0)
                    return "";
                check=0;
            }
        }
        if (check){
            *(preturn+count)=*(*(strs+index)+i);
            count++;
        }
        check=1;
    }
    *(preturn+count)='\0';
    return preturn;
}

/** C faster
char* longestCommonPrefix(char** strs, int strsSize) {
    char *commonPrefix;
    unsigned int currLength;
    unsigned int lowestLength = -1;

    for (int i = 0; i < strsSize; ++i) {
        currLength = strlen(strs[i]);
        if (currLength < lowestLength) {
            lowestLength = currLength;
        }
    }

    if (lowestLength == -1) lowestLength = 0;
    commonPrefix = (char *)malloc(sizeof(char) * (lowestLength + 1));
    memset(commonPrefix, 0, lowestLength + 1);

    for (int i = 0; i < lowestLength; ++i) {
        for (int j = 1; j < strsSize; ++j) {
            if (strs[0][i] != strs[j][i]) {
                return commonPrefix;
            }
        }
        commonPrefix[i] = strs[0][i];
    }

    return commonPrefix;
}
*/
