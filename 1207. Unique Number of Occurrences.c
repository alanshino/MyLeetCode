void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc (const void * a, const void * b);

bool uniqueOccurrences(int* arr, int arrSize){
    int *punique = calloc(2002, sizeof(int));            // �̷��D�N�d��q -1000 <= arr[i] <= 1000 �]�� C �y�����䴩�t�Ư���
    for (int i = 0; i < arrSize; i++) {
        punique[arr[i] + 1000]++;                        // �ҥH�Ҧ����ު����W�� 1000 , �קK�t�Ư���
    }
    qsort(punique, 2002, sizeof(int), cmpfunc);          // �ֳt�Ƨǫ�O�d�ѤU������
    /*for (int i = 0; i >= 0 && punique[i] != 0; i--) {
        printf("%d ", punique[i]);
    }  */
    /*for (int i = 0; i < 2002; i++) {
        if (punique[i] != 0)
            printf("%d ", i);
    }*/
    for (int i = 2001; i >= 0 && punique[i] != 0; i--) {
        if (punique[i] == punique[i - 1])                // �T�w�S������ۦP�ȱo���� , �p�G���ۦP�^�� 0
            return 0;
    }
    return 1;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


/**
Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

*/
