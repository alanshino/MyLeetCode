char* reverseWords(char* s) {
    int i=0,j=0,k=0;
    char c;
    char *ps=s;
    while (*ps!='\0'){
        if (*ps!=' '){
            i++;  //�O�����F�X�Ӧr��
            ps++;
        }else{
            ps-=i;
            for (j=0,k=i-1;j<i/2;j++,k--){  //�}�l�洫 �洫����i/2��
                c=*(ps+j);
                *(ps+j)=*(ps+k);
                *(ps+k)=c;
            }
            ps+=i+1;  // ps���V�������B��,+1�O�]����L�Ů�
            i=0;  //�B�ƭ���
        }
    }
    ps-=i;
    for (j=0,k=i-1;j<i/2;j++,k--){ //���}loop��̫ᴫ�@��
        c=*(ps+j);
        *(ps+j)=*(ps+k);
        *(ps+k)=c;
    }
    ps+=i+1;
    return s;
}
