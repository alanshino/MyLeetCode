int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int i;
    int value=0;
    int max=0;
    for (i=0;i<numsSize;i++){
           if (*(nums+i)==1){
                value++;
                max=(max<value)?value:max;
           }else{
              max=(max<value)?value:max;
              value=0;
           }
    }
    if (max==0) max=value;
    return max;
}
