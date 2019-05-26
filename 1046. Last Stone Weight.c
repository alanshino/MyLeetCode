/** C

int compare (const void * a, const void * b)                  // 一開始想要用快排,但後來選用從大到小排序
{
  return ( *(int*)a - *(int*)b );
}

void largeto(int *stones, int array_size)
{
    int change = 0;
    for (int i = 0; i < array_size; i++) {
        for (int j = 0; j < array_size; j++) {
            if (stones[i] > stones[j] && i != j) {
                change = stones[i];
                stones[i] = stones[j];
                stones[j] = change;
            }
        }
    }
}

int lastStoneWeight(int* stones, int stonesSize){
    int heavy1 = 0, heavy2 = 0, number = stonesSize;
    int *parray = stones;
    if (!stonesSize)
        return 0;
    if (stonesSize == 1)
        return *stones;
    //qsort(stones, stonesSize, sizeof(int), compare);
    largeto(stones, stonesSize);
    while (stonesSize > 1) {
        heavy1 = stones[0];
        heavy2 = stones[1];
        if (heavy1 == heavy2) {
            stones[0] = -1;
            stones[1] = -1;
            stonesSize -= 2;
        }else {
            stones[0] = -1;
            stones[1] = heavy1 - heavy2;
            stonesSize--;
        }
        largeto(stones, number);
    }
   // for (int i = 0; i < number; i++)
   //     printf("%d ",stones[i]);
    for (int i = 0; i < number; i++)
        if (stones[i] != -1)
            return stones[i];
    return 0;
}


/**

int cmp(int *a, int *b) {
    return *a - *b;
}

int lastStoneWeight(int* stones, int stonesSize){
    while (stonesSize > 1) {
        qsort(stones, stonesSize, sizeof(int), cmp);

        stones[stonesSize - 2] = stones[stonesSize-1] - stones[stonesSize - 2];

        stonesSize--;
    }

    return stones[0];
}

*/
