int cmpfunc (const void * a, const void * b);
//void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int largestPerimeter(int* A, int ASize){
    qsort(A, ASize, sizeof(int), cmpfunc);               // ���N array �Ƨ�
    for (int i = ASize - 1; i >= 0; i--) {               // �}�l���X array , �ѥk�ܥ�����]���n���̤j��
        if (i < 2)
            return 0;                                    // �Ѿl���������� 3 �Ӯɪ����^�� 0
        else {
            if (A[i - 1] + A[i - 2] > A[i]) {            // �c���T���α�����䤧�M��ĤT�� , ���䤧�t�p��ĤT��
                return A[i - 1] + A[i - 2] + A[i];       // �p�G����캡������� , �����^�� , �]���q�k��}�l , �@�w�|�O�̤j��
            }
        }
    }
    return 0;
}

int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


int largestPerimeter(int* A, int ASize) {

    int a,b,c;

    a = get_max_num(A, ASize);
    b = get_max_num(A, ASize);
    c = get_max_num(A, ASize);

    while (c > 0)
    {
        if (b + c > a)
        {
            return (a + b + c);
        }
        else
        {
            a = b;
            b = c;
            c = get_max_num(A, ASize);
        }
    }

    return 0;
}

int get_max_num(int *A, int Asize)
{
    int i, max_idx = 0, max = A[0];

    for (i = 1; i < Asize; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
            max_idx = i;
        }
    }

    A[max_idx] = 0;

    return max;
}


