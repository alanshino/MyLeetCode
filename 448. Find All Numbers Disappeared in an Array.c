/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {   // �ϥΨ��t�ƪk
    int *preturn=malloc(sizeof(int)*numsSize);                            // �������t numsSize memory storage
    int i=0,block;                                                        // �������ޭ�
    for (i=0;i<numsSize;i++){
        block=abs(*(nums+i))-1;
        *(nums+block)=(*(nums+block))>0?-*(nums+block):*(nums+block);     // �O���ƴN�令�t��
    }
    *returnSize=0;
    for (i=0;i<numsSize;i++){
        if (*(nums+i)>0){                                                 // ��쥿�ƥN��S������
            *(preturn+*returnSize)=i+1;                                   // �N�ȩ�J,���ޱq0�}�l
            (*returnSize)++;                                              // *returnSize �W�[���^�Ǩ���
        }
    }
    return preturn;
}
