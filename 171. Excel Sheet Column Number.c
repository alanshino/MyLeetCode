int titleToNumber(char* s) {
    int total=0;
    while (*s){
        total=total*26+*s-'@';      // �]��A�n��1,��ASCII�ƦC�W�@��char��@,total�C���|���W26
        s++;
    }
    return total;
}
