char* toLowerCase(char* str) {
    char *ps=str;
    while (*ps!='\0'){
        if (*ps<=90&&*ps>=65){   // 依 ascii 排序找到 A - Z
            *(ps)=*(ps)+32;      // 將大寫轉小寫
            ps++;                // pointer move
        }else
            ps++;
    }
    return str;
}
