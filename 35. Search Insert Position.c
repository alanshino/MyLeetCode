int searchInsert(int* nums, int numsSize, int target) {
    int i=0;
    for (i=0;i<numsSize;i++){
        if (*(nums+i)==target||*(nums+i)>target){  // �p�G����m,�άO�o�{�w�g�W�L
            return i;
        }
    }
    return numsSize;                               // ���S���X�A�ά۵�,�ɦb�̫�
}
