int cmpfunc(const void * a, const void * b);     // �Darray�̪��ƹ�
int arrayPairSum(int* nums, int numsSize) {      // �N�̤p���ۥ[ �ۥ[�Ⱥɥi��̤j
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
