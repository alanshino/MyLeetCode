void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc (const void * a, const void * b){
    return ( *(int*)a - *(int*)b );                                  // 將array重新排列由小到大��
}

int largestSumAfterKNegations(int* A, int ASize, int K) {
    int i,negative=0,return_value=0,index,zero=0,max_value,total=0;
    qsort(A,ASize,sizeof(int),cmpfunc);
    for (i=0;i<ASize;i++) {                                         // 找出負數及0
        if (*(A+i)<0) {
            negative++;
        }
        if (!*(A+i)) {
            zero++;
        }
    }
    if (K) {
        for (index=0;K!=0&&negative!=0;K--,negative--) {            // 從最小數字開始交換
            *(A+index)=-*(A+index);
            index++;
        }
        /*for (i=0;i<ASize;i++) {
            printf("%d ",*(A+i));
        }*/
        if (K%2) {                                                  // 剩餘奇數次
            if (zero) {
                for (i=0;i<ASize;i++) {                             // 含有0相加後回傳
                    total+=*(A+i);
                }
                return total;
            }
            qsort(A,ASize,sizeof(int),cmpfunc);                     // 為含有0重整array
            *(A+0)=-*(A+0);                                         // 調整第一個index的value�齘G
            for (i=0;i<ASize;i++) {
                total+=*(A+i);
            }
            return total;
        }else {
            for (i=0;i<ASize;i++) {                                 // 偶數次直接相加後還傳
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

/** C

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


/** C

int largestSumAfterKNegations(int* A, int ASize, int K) {
    int total[201] = {0};
    int *totalP = total+100;
    int t = 0;
    for(int i = 0; i < ASize;++i){
        int n= A[i];
        ++totalP[n];
        t += n;
    }
    int j = 200;
    for(int i = 0; i < 100;++i,j = j - 2){                            // 反轉負數部分需要增加兩倍的值
        int n = total[i];
        if(K >= n){
            K -= n;
            t += j*n;
        }else{
            t += j*K;
            K = 0;
            break;
        }
    }
    if(K%2 == 1){                                                     // 說明有多餘的反轉數需要一個反轉最小值
        for(int i = 0;i <= 100;++i){
            if(total[i+100] > 0 || total[100-i] > 0){
                t = t-2*i;
                break;
            }
        }
    }
    return t;
}
