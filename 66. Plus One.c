/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *preturn=NULL;
    int slap=0,i=0,count=0;
    if (*(digits+digitsSize-1)<9){                  // �p�G���ݭn�i��,�����[1��return
        (*(digits+digitsSize-1))++;
        *returnSize=digitsSize;
        return digits;
    }
    for (i=0;i<digitsSize;i++){                     // �P�_�O�_��������9,�N����i��
        if (*(digits+i)==9){
            slap++;
        }else{
            break;
        }
    }
    if (slap==digitsSize){                           // �p�G���i��
        preturn=malloc(sizeof(int)*(digitsSize+1));  // malloc�@�Ӥ��array�j�@�Ӧ�m���Ŷ�
        *returnSize=digitsSize+1;
        for (i=0;i<digitsSize+1;i++){                // �u���}�Y��1,��L���O0
            if (i==0){
                *(preturn+i)=1;
            }else{
                *(preturn+i)=0;
            }
        }
        return preturn;
    }else{
        *returnSize=digitsSize;                     // �p�G���ݭn�i��,�����O���i��
        for (i=digitsSize-1;i>=0;i--){              // �令�q�̫��}�l
            if (*(digits+i)==9){
                count=1;                            // �Τ@��count�Ӭ����O�_���i��
                *(digits+i)=0;                      // �����]��0
            }else if (count){                       // �����i��,���e�����i��
                count=0;
                (*(digits+i))++;                    // ����[1
                return digits;                      // ����return
            }
        }
    }
    return digits;
}
