int removeDuplicates(int* nums, int numsSize){
    int tag = 0, number = 0, index = 0;
    tag = *(nums + 0);                                 // �����Ĥ@�Ӫ�l��
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return 1;
    for (int i = 1; i < numsSize; i++) {               // ������l¾�᪺�Ҧ��ۦP�ƭȧ����
        if (tag == nums[i]) {                          // �o�ӸѪk���ܤj���|�} , ������n�t���]�w������ , �N�|�X��
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
        if (*(nums + i) == -10000000) {                // �q�s���X array �o�{�J�����
            //index++;
            //printf("%d ",index);
            ;
        }else {
            nums[index] = nums[i];                     // �N index ���ȧאּ�᭱���D����
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
        if(nums[i] != nums[rank])                      // ���D�ۦP�ƭ�
        {
            rank++;                                    // �����
            nums[rank] = nums[i];
            //printf("%d ",nums[rank]);
        }
    }
    return rank+1;                                     // �]���|�ֺ�� index ���s�����Ӥ��� , �ҥH�^�ǮɻݼW�[
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
