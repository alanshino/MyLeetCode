int searchInsert(int* nums, int numsSize, int target) {
    int i=0;
    for (i=0;i<numsSize;i++){
        if (*(nums+i)==target||*(nums+i)>target){  // 狦т竚,┪琌祇瞷竒禬筁
            return i;
        }
    }
    return numsSize;                               // 常⊿т続┪单,干程
}
