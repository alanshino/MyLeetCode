int minDeletionSize(char** A, int ASize) {
    int i=0,j=0,index=0;
    int k=strlen(*(A));
    for (i=0;i<k;i++){                          // �~�椺�C
        for (j=0;j<ASize-1;j++){                // �p�G�S�����W,�N��W�@�ӽs�X�j��U�@��
            if (*(*(A+j)+i)>*(*(A+j+1)+i)){
                index++;                        // �ק�ƥ[�@
                break;
            }
        }
    }
    return index;
}
