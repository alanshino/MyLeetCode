int lengthOfLastWord(char* s) {
    int number=strlen(s);
    int word=0,i=0,step=0;
    char *p=s+number-1; //從後面走過來算
    if (number==0) return 0;
    while (*p==' '){
        p--;
        i++;
        if (i==number) return 0;
    }
    step=i;
    i=0;
    while (*p!=' '){
        p--;
        word++;
        i++;
        if (i+step==number) return word;
    }
    return word;
}
