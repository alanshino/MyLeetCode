/** C

    ���N array �ƻs�@���A�Χֳt�ƧǪk�Ƨǫ�N��� array ����O�_���Ҥ��P , �^�Ǥ��P�������Ӽ�

int bubble_sort(int *heights, int heightsSize);
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc (const void * a, const void * b);

int heightChecker(int *heights, int heightsSize){
    int swap_time = 0;
    int *temp = malloc(sizeof(int) * heightsSize);
    for (int i = 0; i < heightsSize; i++) {
        temp[i] = heights[i];
    }
    qsort(heights, heightsSize, sizeof(int), cmpfunc);
    for (int i = 0; i < heightsSize; i++) {
        if (temp[i] != heights[i])
            swap_time++;
    }
    return swap_time;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int bubble_sort(int *heights, int heightsSize)
{
    int swap = 0, time = 0;
    for (int i = 0; i < heightsSize; i++) {
        for (int j = 0; j < heightsSize; j++) {
            if (heights[i] < heights[j]) {
                swap = heights[i];
                heights[i] = heights[j];
                heights[j] = swap;
                time++;
            }
        }
    }
    return time;
}

*/
