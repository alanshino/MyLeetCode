void moveZeroes(int* nums, int numsSize) {
    int i=0,j=0,temp;
    if (numsSize==1) return;                  // ��@���ު����^��
    while (j<numsSize){
        if (!(*(nums+j)))                     // ���Ʀr0�O�U����
            j++;
        else{
            temp=*(nums+i);                   // ��ƥ洫
            *(nums+i)=*(nums+j);
            *(nums+j)=temp;
            i++;
            j++;
        }
    }
}
