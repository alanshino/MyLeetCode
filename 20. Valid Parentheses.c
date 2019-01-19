bool isValid(char* s) {
    int stack[1000000]={0};                                  // stack �Ŷ�
    int count=0;
    if (*s=='\0'){                                           // �Ť]���u
        return 1;
    }else{
        while (*s){
            if (*s=='('||*s=='['||*s=='{'){                  // �p�G�����b��,��i���|
                stack[count]+=*s;
                count++;                                     // ���|�p�ƥ[1
            }else{
                if (*s==')'){
                    if (count!=0&&stack[count-1]=='('){      // �p�G�P�W�@��push,�ۦP�N�N�����ﲾ�X���|
                        stack[count-1]=0;
                        count--;
                    }else{
                        return 0;                            // ���P�N����return 0
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
        if (count==0){                                     // ��������,�p�ƾ�����0
            return 1;
        }else{                                             // ������Ŷ��̬���
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
