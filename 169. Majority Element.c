int cmpfunc(const void * a, const void * b);
int majorityElement(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmpfunc);  // 快速排序
    return *(nums+numsSize/2);                 // 回傳中間值的數
    return 0;
}

int cmpfunc(const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int majorityElement(int* nums, int numsSize) {  // the faster
    int elem = 0;
    int count = 0;                              // 計算次數
    for(int i = 0; i < numsSize; i++){          // 走訪array
        if(count ==0 ){                         // 剛開始為零,從頭開始找
            elem = nums[i];
            count = 1;
        }else{
            if(elem == nums[i]) count++;       // 如果下個數相同,就加一
            else count--;                      // 如果下個數不同,就歸零
        }                                      // 如果有一個數大於整個array元素的2倍,一定會使count大於1
    }
    return elem;
}
