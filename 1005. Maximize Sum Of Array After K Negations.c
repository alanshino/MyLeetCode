void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc (const void * a, const void * b){
    return ( *(int*)a - *(int*)b );                                  // ��array����������С����C
}

int largestSumAfterKNegations(int* A, int ASize, int K) {
    int i,negative=0,return_value=0,index,zero=0,max_value,total=0;
    qsort(A,ASize,sizeof(int),cmpfunc);
    for (i=0;i<ASize;i++) {                                         // �ҳ�ؓ����0
        if (*(A+i)<0) {
            negative++;
        }
        if (!*(A+i)) {
            zero++;
        }
    }
    if (K) {
        for (index=0;K!=0&&negative!=0;K--,negative--) {            // ����С�����_ʼ���Q
            *(A+index)=-*(A+index);
            index++;
        }
        /*for (i=0;i<ASize;i++) {
            printf("%d ",*(A+i));
        }*/
        if (K%2) {                                                  // ʣ�N�攵��
            if (zero) {
                for (i=0;i<ASize;i++) {                             // ����0�����؂�
                    total+=*(A+i);
                }
                return total;
            }
            qsort(A,ASize,sizeof(int),cmpfunc);                     // �麬��0����array
            *(A+0)=-*(A+0);                                         // �{����һ��index��value�p��
            for (i=0;i<ASize;i++) {
                total+=*(A+i);
            }
            return total;
        }else {
            for (i=0;i<ASize;i++) {                                 // ż����ֱ�������߀��
                total+=*(A+i);
            }
            return total;
        }
    }else {
        for (i=0;i<ASize;i++) {
            total+=*(A+i);
        }
        return total;
    }
    return 0;
}


/** C another
int partition(int *A, int low, int high)
{
    int tmp = A[low];
    while(low < high)
    {
        while(low < high && A[high] >= tmp)
            high--;
        if(low < high)
            A[low++] = A[high];
        while(low < high && A[low] <= tmp)
            low++;
        if(low < high)
            A[high--] = A[low];
    }
    A[low] = tmp;
    return low;
}

void quick_sort(int*A, int start, int end)
{
    int pos;
    if(start < end)
    {
        pos  = partition(A, start, end);
        quick_sort(A, start, pos - 1);
        quick_sort(A, pos + 1, end);
    }
}


int add_sum(int *A, int Asize)
{
    int sum = 0;
    for(int i = 0; i < Asize; i++)
        sum += A[i];
    return sum;
}

int largestSumAfterKNegations(int* A, int ASize, int K) {
    quick_sort(A, 0, ASize - 1);
    int n = K;
    for(int i = 0; i < K; i++)
    {
        if(A[i] < 0)
        {
            A[i] = -A[i];
            n--;
        }
        else
        {
            break;
        }
    }

    if(n > 0 && 1 == n % 2)
    {
            quick_sort(A, 0, ASize - 1);
            A[0] = -A[0];
            return add_sum(A, ASize);
    }

    return add_sum(A, ASize);
}
*/
