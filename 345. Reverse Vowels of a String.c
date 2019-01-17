char* reverseVowels(char* s) {
    int a=strlen(s);
    char *pc=s+a-1;                  //紀錄最後一個
    char *ps=s;                      //紀錄第一個
    int temp=0;
    while (ps<=pc){
        if (*ps=='a'||*ps=='e'||*ps=='i'||*ps=='o'||*ps=='u'||*ps=='A'||*ps=='E'||*ps=='I'||*ps=='O'||*ps=='U'){     // 條件符合
            if (*pc=='a'||*pc=='e'||*pc=='i'||*pc=='o'||*pc=='u'||*pc=='A'||*pc=='E'||*pc=='I'||*pc=='O'||*pc=='U'){ // 條件符合
                temp=*pc;
                *pc=*ps;
                *ps=temp;
                ps++;             // 互換完後各自往後往前一格
                pc--;
            }else{
                pc--;             // 如果不符合,就往前一格
            }
        }else{
            ps++;                 // 如果不符合,就往後一格
        }
    }
    return s;
}
