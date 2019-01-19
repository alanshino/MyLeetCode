bool isLongPressedName(char* name, char* typed) {
    int a[26]={0},slap=0,temp=0;
    int b[26]={0};
    if (*name!=*typed) return 0;            // 如果第一個就不同,直接return 0
    while (*typed){
        if (*typed!=*name) return 0;        // 字不同直接return 0
        while (*typed==*name){
            a[*typed-97]++;                 // 算打了幾個字
            typed++;
        }
        slap=*(typed-1);                    // 因為移動,所以要用一個var來保存上一次的位置的值
        temp=*name;                         // 紀錄另一個字的值
        while (temp==*name){
            b[temp-97]++;                   // 算打了幾次
            name++;
        }
        if (b[temp-97]>a[slap-97]){         // 多按的部分依定要比原來的字數多
            return 0;
        }else{
            b[temp-97]=0;                   // 歸0
            a[slap-97]=0;
        }
    }
    if (*name=='\0'&&*typed=='\0') return 1; // 如果有一部分沒走完,直接return 0
    else return 0;
}

/**
bool isLongPressedName(char* name, char* typed) {
    int typeLen = strlen(typed);
    int nameLen = strlen(name);
    int i, j = 0;
    for(i = 0; i < typeLen; i++){
        if(name[j] == typed[i] && j < nameLen){
            j++;
        }
        else if(typed[i] == typed[i-1]){
            continue;
        }
        else
            return false;
    }
    if(j != nameLen)
        return false;
    return true;
}
*/
