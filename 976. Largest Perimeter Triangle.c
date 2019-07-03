int cmpfunc (const void * a, const void * b);
//void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int largestPerimeter(int* A, int ASize){
    qsort(A, ASize, sizeof(int), cmpfunc);               // 先將 array 排序
    for (int i = ASize - 1; i >= 0; i--) {               // 開始走訪 array , 由右至左的原因為要找到最大者
        if (i < 2)
            return 0;                                    // 剩餘的元素不足 3 個時直接回傳 0
        else {
            if (A[i - 1] + A[i - 2] > A[i]) {            // 構成三角形條件兩邊之和於第三邊 , 兩邊之差小於第三邊
                return A[i - 1] + A[i - 2] + A[i];       // 如果有找到滿足條件者 , 直接回傳 , 因為從右邊開始 , 一定會是最大者
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


