void rotate(int* nums, int numsSize, int k) {
    int temp,i=0,j=0;
    for (i=0;i<k;i++){                      // 記錄交換幾次
        temp=*(nums+numsSize-1);            // 紀錄最後一位的數值
        for (j=numsSize-1;j>0;j--){         // 由最後開始走,避免使用到已放置更新的數值
            *(nums+j)=*(nums+j-1);          // 放置上一位的數值
        }
        *(nums)=temp;                       // 將第一個數值放入剛剛紀錄的最後一位數值
    }
    return ;
}

/** C faster
void rotate(int* nums, int numsSize, int k) {
    int n = k % numsSize;
    int *out;

    if (n == numsSize) {
        return;
    }
    if (n == 1) {
        int i;
        int last = nums[numsSize - 1];
        for (i = numsSize - 1; i >= 1; --i) {
            nums[i] = nums[i - 1];
        }
        nums[0] = last;
        return;
    }
    out = (int *)malloc(numsSize * sizeof(int));
    if (out != NULL) {
        int j = numsSize - n;
        int i;

        for (i = 0; i < n; ++i, ++j) {
            out[i] = nums[j];
        }
        for (j = 0; i < numsSize; ++i, ++j) {
            out[i] = nums[j];
        }
        for (i = 0; i < numsSize; ++i) {
            nums[i] = out[i];
        }
        free(out);
    } else {
        rotate(nums, numsSize, k - 1);
        rotate(nums, numsSize, 1);
    }
}
*/
/** C
void rotate(int* nums, int numsSize, int k) {
    int pos=0, posnew=0;
    int prev=0;
    int temp, start;
    int count=0;

    k=k%numsSize;

    for(start=0; start<numsSize; start++)
    {
        pos=start;
        prev=nums[start];
        do
        {
            posnew=(pos+k)%numsSize;
            temp=nums[posnew];
            nums[posnew]=prev;
            prev=temp;
            pos=posnew;
            count++;
        }while(start!=pos);
        if(count==numsSize){
            break;
        }
    }

    return nums;
}
*/
/** C faster
void reverse(int* nums, int start,int end){
    while(start<end){
        int temp = nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;end--;
    }
}
void rotate(int* nums, int numsSize, int k) {
    k=k%numsSize;
    reverse(nums,0,numsSize-1);
    reverse(nums,0,k-1);
    reverse(nums,k,numsSize-1);
}
*/
/** Java
public class Solution {
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }
    public void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}
*/
/** Java
public class Solution {
    public void rotate(int[] nums, int k) {
        int[] a = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            a[(i + k) % nums.length] = nums[i];
        }
        for (int i = 0; i < nums.length; i++) {
            nums[i] = a[i];
        }
    }
}
*/
