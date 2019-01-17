bool containsDuplicate(int* nums, int numsSize) {
    int i=0,j=0;
    for (i=0;i<numsSize;i++){
        for (j=0;j<numsSize;j++){
            if (i==j){
                continue;
            }else{
                if (*(nums+i)==*(nums+j)){
                    return 1;
                }
            }
        }
    }
    return 0;
}
