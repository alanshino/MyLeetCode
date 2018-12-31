int cmpfunc(const void * a, const void * b);     // 求array裡的數對
int arrayPairSum(int* nums, int numsSize) {      // 將最小的相加 相加值盡可能最大
    int total=0;
    int i;
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    for (i=0;i<numsSize;i+=2){
        total+=*(nums+i);
    }
    return total;
}

int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
