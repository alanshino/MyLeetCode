int titleToNumber(char* s) {
    int total=0;
    while (*s){
        total=total*26+*s-'@';      // 因為A要為1,按ASCII排列上一個char為@,total每次會乘上26
        s++;
    }
    return total;
}
