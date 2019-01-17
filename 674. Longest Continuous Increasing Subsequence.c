int findLengthOfLCIS(int* nums, int numsSize) {
    int i=0,total=1,max=1;
    if (numsSize==0) return 0;
    for (i=0;i<numsSize-1;i++){
        if (*(nums+i)<*(nums+i+1)){
            total++;
        }else{
            if (total>max){
                max=total;
            }
            total=1;
        }
    }
    if (total>max){
        max=total;
    }
    return max;
}
