/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc (const void * a, const void * b);
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int *preturn = malloc(sizeof(int) * arr1Size);
    int start = 0;
    int count = 0;
    *returnSize = arr1Size;
    for (int i = 0; i < arr2Size; i++) {                    // arr2 �]�t�D�حn�D���ƦC���� , �ҥH��b�~��
        for (int j = 0; j < arr1Size; j++) {                // �v�Ԩ��X arr1 , �d��ۦP�������w���s�Ƨ�
            if (arr1[j] == -1)
                continue;
            if (arr1[j] == arr2[i]) {
                preturn[count] = arr1[j];
                arr1[j] = -1;                               // �Ƨǧ��������]�m�� -1
                count++;
            }
        }
    }
    qsort(arr1, arr1Size, sizeof(int), cmpfunc);            // �i��ֳt�Ƨ�
  /*  for (int i = 0; i < arr1Size, count < arr1Size; i++) {// �쥻�H���O���ӭ����������m�����ƦC
        if (arr1[i] != -1) {
            preturn[count] = arr1[i];
            arr1[i] = -1;
            count++;
        }
    } */
    for (int i = count; i < arr1Size; i++) {                // �����N�ֳt�Ƨǧ���Ѿl������ , ��J�^�� array
        preturn[count++] = arr1[i];
    }
    /** �����դ����� , ���ѱ���t�׷|���ɤ@��
    for (int i = 0; i < arr1Size; i++) {
        printf("%d ",preturn[i]);
    }
    */
    return preturn;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
