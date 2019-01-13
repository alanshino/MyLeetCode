int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int i,j;
    int a[10001]={0};
    int *preturn=NULL;
    *returnSize=2;
    preturn=malloc(sizeof(int)**returnSize);
    for (i=0;i<numsSize;i++){
        a[*(nums+i)]++;
    }
    for (i=1;i<=numsSize;i++){
        if (a[i]==2){
            *(preturn+0)=i;
        }
        if (a[i]==0){
            *(preturn+1)=i;
        }
    }
    return preturn;
}
