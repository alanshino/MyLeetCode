char* convertToTitle(int n) {
    int total=0,n1=n,status=0,i=0;
    char *preturn=NULL,*pc=NULL;
    while (n1>0){                                       // �Д���Ҫ�ׂ����g�Ĵ�С
        n1/=26;
        total++;
    }
    preturn=malloc(sizeof(char)*(total+1));
    pc=malloc(sizeof(char)*(total+1));
    while (n>0){
        status=n%26;
        n/=26;
        if (!status){
            *(preturn+i)='Z';                          // ���� Z ����Mλ����Ҫ�p 1
            i++;
            n--;
        }else{
            *(preturn+i)=status+'@';                   // 'A' is 1 , ASCII '@' is 'A' - 1
            i++;
        }
    }
    *(preturn+i)='\0';
    //printf("%s\n",preturn);
    for (i=total-1,n1=0;i>=0;i--,n1++){
        if (*(preturn+i)>='A'&&*(preturn+i)<='Z'){     // ���ִ�����
            *(pc+n1)=*(preturn+i);
        }
        else{
            n1--;                                      // �����Ǵ���Ԫ,��Ҫ�Ȍ��ƄӸ�׃����ֵ,������^�g����׃��,���Ԝp 1 ����ԭֵ
            continue;
        }
    }
    *(pc+n1)='\0';
    free(preturn);                                     // ጷ��D��ǰ���ִ�
    return pc;
}
