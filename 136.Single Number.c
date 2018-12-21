int singleNumber(int* nums, int numsSize) {
    int i=0,j=0;
    int *pans=malloc(sizeof(int)*numsSize);
    for (i=0;i<numsSize;i++){
        *(pans+i)=0;
    }
    for (i=0;i<numsSize;i++){
        for (j=0;j<numsSize;j++){
            if (*(nums+i)==*(nums+j)){
                (*(pans+i))++;
            }
        }
    }
    for (i=0;i<numsSize;i++){
        if (*(pans+i)==1){
            return *(nums+i);
        }
    }
    return 0;
}
