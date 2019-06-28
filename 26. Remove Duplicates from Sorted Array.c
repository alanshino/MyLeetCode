int removeDuplicates(int* nums, int numsSize){
    int tag = 0, number = 0, index = 0;
    tag = *(nums + 0);                                 // 紀錄第一個初始直
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return 1;
    for (int i = 1; i < numsSize; i++) {               // 扣除初始職後的所有相同數值更改其值
        if (tag == nums[i]) {                          // 這個解法有很大的漏洞 , 當測資剛好含有設定的更改值 , 就會出錯
            nums[i] = -10000000;
            number++;
        }else {
            tag = nums[i];
        }
    }
    /*for (int i = 0; i < numsSize; i++) {
        printf("%d ",nums[i]);
    }*/
    for (int i = 0; i < numsSize; i++) {
        if (*(nums + i) == -10000000) {                // 從新走訪 array 發現遇到更改值
            //index++;
            //printf("%d ",index);
            ;
        }else {
            nums[index] = nums[i];                     // 將 index 的值改為後面的非更改值
            //printf("%d ",nums[i]);
            index++;
        }
    }
    return numsSize - number;
}

int removeDuplicates(int* nums, int numsSize){

    int i = 0; // position
    int rank = 0; //num
    if(nums == NULL || numsSize == 0)
    {
        return rank;
    }
    for(;i < numsSize;i++)
    {
        if(nums[i] != nums[rank])                      // 找到非相同數值
        {
            rank++;                                    // 更改其值
            nums[rank] = nums[i];
            //printf("%d ",nums[rank]);
        }
    }
    return rank+1;                                     // 因為會少算到 index 為零的那個元素 , 所以回傳時需增加
}

int removeDuplicates(int* nums, int numsSize){

    int i,j,temp;
    j=1;

    if((numsSize==0)||(numsSize==1)){
        return numsSize;
    }
    for(i=1;i<numsSize;i++){
        if(nums[i-1]==nums[i]){
            //printf("%d %d\n",nums[i-1],nums[i]);
            continue;
        }else{
            temp = nums[i];
            nums[j]=nums[i];
            nums[i]=temp;
            j++;
        }
    }

    return j;
}
