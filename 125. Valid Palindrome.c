void str_tolower(char *s);
bool isPalindrome(char* s) {
    int i,j;
    int length=strlen(s);
    str_tolower(s);                                                // 全部轉換成小寫
    for (i=0,j=length-1;i<j;){
        if (*(s+i)>=97&&*(s+i)<=122||*(s+i)>=48&&*(s+i)<=57){      // 小寫英文字母,或是數字 0 ~ 9 (從前面開始走)
            ;
        }else{
            i++;
            continue;
        }
        if (*(s+j)>=97&&*(s+j)<=122||*(s+j)>=48&&*(s+j)<=57){      // 小寫英文字母,或是數字 0 ~ 9 (從最後開始走)
            ;
        }else{
            j--;
            continue;
        }
        if (*(s+i)==*(s+j))                                        // 如果相同,同步增減 // 判斷是否回文
            i++,j--;
        else
            return 0;

    }
    return 1;
}

void str_tolower(char *s){
    while (*s){
        if (*s>=65&&*s<=90){
            *s=*s+32;                                              // 小寫轉換, ASCII 排序相差32
        }
        s++;
    }
    return ;
}


/** C faster
inline char lower(char c){ return (c|' '); }
inline bool a2z(char c){ return lower(c)<='z' && lower(c) >= 'a'; }
inline bool isnum(char c){ return c>='0' && c<='9'; }
bool isPalindrome(char* s) {
    char* e;
    for(e=s; *e!='\0'; e++){}
    while(e>s){
        if(!a2z(*e) && !isnum(*e)){
            e--;
            continue;
        }
        if(!a2z(*s) && !isnum(*s)){
            s++;
            continue;
        }
        if(lower(*e) != lower(*s)) return 0;
        e--;
        s++;
    }
    return 1;
}
*/
