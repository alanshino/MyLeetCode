/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char* S, int* returnSize) {
    int i=0;
    int line=1,unit=0,length=100;                     // �C�C100�Ŷ�
    int *preturn=malloc(sizeof(int)*2);
    *returnSize=2;
    while (*S){
        if (length-*(widths+*S-97)>=0){               //  �Ѿl�Ŷ���h�o�Ӧr���ݨD�Ŷ�
            length-=*(widths+*S-97);                  //  ������������
            S++;
        }else{
            line++;                                   //  �����}�U�@�C
            length=100;                               //  ���s���t��100�Ŷ�
        }
    }
    *(preturn+0)=line;                                //  �����ϥΦC��
    *(preturn+1)=100-length;                          //  �O���ثe�ϥΨ쪺���,�]���ĥδ�k(�N��o�C�٦��h�֪Ŷ�),�ҥH�n��100�Ŷ��Ӻ�
    return preturn;
}
