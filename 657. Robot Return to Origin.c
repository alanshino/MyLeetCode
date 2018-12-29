bool judgeCircle(char* moves) {
    int *pa=malloc(sizeof(int)*2);
    int i=0;
    *(pa+0)=0;
    *(pa+1)=0;
    if (*moves=='\0') return 1;
    while (*moves!='\0'){
        if (*moves=='U'){
            (*(pa+0))--;
        }else if (*moves=='D'){
            (*(pa+0))++;
        }else if (*moves=='L'){
            (*(pa+1))--;
        }else{
            (*(pa+1))++;
        }
        moves++;
    }
    if (*(pa+0)==0 && *(pa+1)==0){
        return 1;
    }else{
        return 0;
    }
}
