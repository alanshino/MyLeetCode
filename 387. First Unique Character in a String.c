int firstUniqChar(char* s) {
    int a[26]={0};
    char *ps=s;                  //pointer to char to remember location
    int i=0;
    while (*s){
        a[*s-97]++;              //依照ascii碼增加array的值
        s++;                     //pointer++ add char size
    }
    while (*ps){
        if (a[*ps-97]==1){       //找到第一個單數值,從原始字串開始找
            return i;            //return location
        }
        ps++;                    //pointer++
        i++;                     //location++
    }
    return -1;                   //沒找到回傳-1
}
