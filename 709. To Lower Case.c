char* toLowerCase(char* str) {
    char *ps=str;
    while (*ps!='\0'){
        if (*ps<=90&&*ps>=65){   // �� ascii �Ƨǧ�� A - Z
            *(ps)=*(ps)+32;      // �N�j�g��p�g
            ps++;                // pointer move
        }else
            ps++;
    }
    return str;
}
