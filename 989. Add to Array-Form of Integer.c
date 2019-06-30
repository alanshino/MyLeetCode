/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count(int K);
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
    int number = count(K);                                                      // ���o K ���Ӽ�
    int digit_add = 0, carry = 0;
    int malloc_size = (number > ASize) ? number + 1 : ASize + 1;
    int *preturn = malloc(sizeof(int) * malloc_size);                           // ���t�^�ǪŶ� , ��ܤ� K �ӼƩM�D�ص��w�� array �٭n�j�@�ӯ��ު��Ŷ� (�ΨӦs��i��)
    int *pput_number = malloc(sizeof(int) * (malloc_size - 1));                 // ���t�@�ӪŶ��ΨӱN K ���ƭ��ഫ�� array ���Φ� (��1�]�����ݫO�d�i�����)
    int *pcheck = NULL;                                                         // �A�w�d�@�ӪŶ�
    for (int i = malloc_size - 2; i >= 0; i--) {
        pput_number[i] = K % 10;
        K /= 10;
        //printf("%d ",pput_number[i]);
    }
    if (number > ASize) {                                                       // �p�G K �ƭ��ഫ�� array ���D�ص��w�� array �٭n�j
        pcheck = malloc(sizeof(int) * (malloc_size - 1));                       // �A�t�m�@�ӪŶ� , �e�������޸� 0 , �ӫO����Ӭۥ[ array ���@�P��
        for (int i = 0; i < malloc_size - 1 - ASize; i++) {
            pcheck[i] = 0;
        }
        for (int i =  malloc_size - 1 - ASize, j = 0; i < malloc_size - 1; i++, j++) {
            pcheck[i] = A[j];
        }
        for (int i =  0; i < malloc_size - 1; i++) {
            printf("%d ",pcheck[i]);
        }
        for (int i = malloc_size - 2, j = malloc_size - 1; j >= 0; i--, j--) {               // �]�����ު��_�l�I���@�� , �ҥH������ت�F�榡
            if (!j) {                                                                        // ��F�̫�@�Ӧ^�ǯ��ޮ� , �p�G���i��� 1 , �Ϥ��� 0
                if (carry)
                    preturn[j] = 1;
                else
                    preturn[j] = 0;
            }else {
                if (carry)
                    digit_add = pput_number[i] + pcheck[i] + 1;
                else
                    digit_add = pput_number[i] + pcheck[i];
                if (digit_add >= 10) {                                                      // �O�d�i���
                    carry = 1;
                    digit_add = digit_add % 10;
                    preturn[j] = digit_add;
                }else {
                    carry = 0;
                    digit_add = digit_add % 10;
                    preturn[j] = digit_add;
                }
            }
        }
    }else {
        for (int i = malloc_size - 2, j = malloc_size - 1; j >= 0; i--, j--) {
            if (!j) {
                if (carry)
                    preturn[j] = 1;
                else
                    preturn[j] = 0;
            }else {
                if (carry)
                    digit_add = pput_number[i] + A[i] + 1;
                else
                    digit_add = pput_number[i] + A[i];
                if (digit_add >= 10) {
                    carry = 1;
                    digit_add = digit_add % 10;
                    preturn[j] = digit_add;
                }else {
                    carry = 0;
                    digit_add = digit_add % 10;
                    preturn[j] = digit_add;
                }
            }
        }
    }
    //printf("%d %d",malloc_size - 1,malloc_size);
    /*for (int i = 0; i < malloc_size - 1; i++) {
        printf("%d ",pput_number[i]);
    }*/
    /*for (int i = 0; i < malloc_size; i++) {
        printf("%d ",preturn[i]);
    }*/
    if (preturn[0] == 0) {                                                              // �^�ǯ��޲Ĥ@�Ӧp�G��0 , �h�N��S���i��
        *returnSize = malloc_size - 1;
        return preturn + 1;
    }
    *returnSize = malloc_size;                                                          // �Ϥ����i��
    return preturn;
}

int count(int K)
{
    int i = 0;
    while (K) {
        K /= 10;
        i++;
    }
    return i;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
    int i;
    for (i=ASize-1;i >=0; i--) {
        A[i] += K;
        K = A[i] / 10;
        A[i] %= 10;
    }

    int carry_bit_n = 0, temp = K;
    while(temp) {
        carry_bit_n ++;
        temp /= 10;
    }
    *returnSize = ASize + carry_bit_n;
    int* res = (int*)malloc(*returnSize*sizeof(int));
    for (temp = 0; temp < ASize; temp++)
        res[temp+carry_bit_n] = A[temp];
    while (K) {
        res[--carry_bit_n] = K % 10;
        K /= 10;
    }

    return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
    int len = ASize > 10 ? ASize+1 : 11;
    int* res = malloc(len * sizeof(int));
    int i = ASize-1, j = len-1;
    for(; i>=0; i--, j--) {
        K = A[i] +K;
        res[j] = K%10;
        K /= 10;
    }
    for(;K>0;K/=10,j--) res[j] = K%10;
    *returnSize = len-j-1;
    return res+j+1;
}
