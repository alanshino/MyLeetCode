bool rotateString(char* A, char* B) {
    int n1=strlen(A),i=0,last=0,j=0;
    int n2=strlen(B);
    char temp=0;
    char *pa=A,*pb=B;
    if (n1!=n2){                       // �r����פ��P,�L�k���
        return 0;
    }
    if (*A=='\0'&&*B=='\0') return 1;  // �Ŧr�ꬰ�u
    for (i=0,last=n1-1;i<n1;i++){
        temp=*(pa+0);                  // ���o����m����
        for (j=0;j<last;j++){          // �᭱��m�̧ǦV�e�ƦC
            *(pa+j)=*(pa+j+1);
        }
        *(pa+last)=temp;               // �̫�@�Ӭ����r����
        if (same(A,B)){                // �p�G�ۦP���u
            return 1;
        }else{
            continue;
        }
    }
    return 0;
}

int same(char *pa,char *pb){
    int i=0;
    while (*pa){
        if (*pa==*pb){                // �P�_�O�_�ۦP
            pa++;
            pb++;
        }else{
            return 0;
        }
    }
    return 1;
}
