bool isValid(char* s) {
    int stack[1000000]={0};                                  // stack 空間
    int count=0;
    if (*s=='\0'){                                           // 空也為真
        return 1;
    }else{
        while (*s){
            if (*s=='('||*s=='['||*s=='{'){                  // 如果為左半邊,放進堆疊
                stack[count]+=*s;
                count++;                                     // 堆疊計數加1
            }else{
                if (*s==')'){
                    if (count!=0&&stack[count-1]=='('){      // 如果與上一個push,相同就將它成對移出堆疊
                        stack[count-1]=0;
                        count--;
                    }else{
                        return 0;                            // 不同就直接return 0
                    }
                }else if (*s==']'){
                    if (count!=0&&stack[count-1]=='['){
                        stack[count-1]=0;
                        count--;
                    }else{
                        return 0;
                    }
                }else if (*s=='}'){
                    if (count!=0&&stack[count-1]=='{'){
                        stack[count-1]=0;
                        count--;
                    }else{
                        return 0;
                    }
                }
            }
            s++;
        }
        if (count==0){                                     // 全部成對,計數器應為0
            return 1;
        }else{                                             // 有任何空閒者為假
            return 0;
        }
    }
}

/** the faster
bool isValid(char* s) {
    int i=strlen(s);
    char *stack=calloc(sizeof(char),i);
    int count=0;
    if (*s=='\0'){
        return 1;
    }else{
        while (*s){
            if (*s=='('||*s=='['||*s=='{'){
                stack[count]+=*s;
                count++;
            }else{
                if (*s==')'){
                    if (count!=0&&stack[count-1]=='('){
                        stack[count-1]=0;
                        count--;
                    }else{
                        return 0;
                    }
                }else if (*s==']'){
                    if (count!=0&&stack[count-1]=='['){
                        stack[count-1]=0;
                        count--;
                    }else{
                        return 0;
                    }
                }else if (*s=='}'){
                    if (count!=0&&stack[count-1]=='{'){
                        stack[count-1]=0;
                        count--;
                    }else{
                        return 0;
                    }
                }
            }
            s++;
        }
        if (count==0){
            return 1;
        }else{
            return 0;
        }
    }
}
*/
