/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int i,n=0,*preturn=NULL;
    for (i=left;i<=right;i++){  // �qleft number��right number
        if (digitalright(i)){
            n++;                // �T�w���X�ӲŦX����
        }
    }
    *returnSize=n;
    preturn=malloc(sizeof(int)* *returnSize); // ���t�j�p
    n=0;
    for (i=left,n=0;i<=right;i++){
        if (digitalright(i)){   // �N�ŦX���󪺩�iarray
            *(preturn+n)=i;
            n++;
        }
    }
    return preturn ;
}

int digitalright(int i){
    int digital=0;
    int n=i;
    while (i){
        digital=i%10;          // ���̫�@��
        if (digital==0){       // �D�حn�D���o��0
            return 0;
        }else if (n%digital==0){  // �̫�@��ƥi�㰣���
            i=i/10;               // ��ƴ�h�̫�@���
        }else{
            return 0;
        }
    }
    return 1;
}
