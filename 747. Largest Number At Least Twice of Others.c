int dominantIndex(int* nums, int numsSize) {
    int max=0;
    int i=0,block=0;
    for (i=0;i<numsSize;i++){
        if (*(nums+i)>max){
            max=*(nums+i);
            block=i;
        }
    }
    for (i=0;i<numsSize;i++){
        if (*(nums+i)*2<=max){
            continue;
        }else if (i==block){
            continue;
        }else{
            return -1;   
        }
    }
    return block;
}
