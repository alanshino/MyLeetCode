/* 1464. Maximum Product of Two Elements in an Array */
/**
 * Given the array of integers nums, you will choose two different indices i and j of that array.
 * Return the maximum value of (nums[i]-1)*(nums[j]-1).
 * ---------------------------------------------------------------------------------------------
 * Example 1:
    Input: nums = [3,4,5,2]
    Output: 12
    Explanation: If you choose the indices i=1 and j=2 (indexed from 0),
    you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12.
 * ---------------------------------------------------------------------------------------------
 * Example 2:
    Input: nums = [1,5,4,5]
    Output: 16
    Explanation: Choosing the indices i=1 and j=3 (indexed from 0),
    you will get the maximum value of (5-1)*(5-1) = 16.
 * ---------------------------------------------------------------------------------------------
 * Example 3:
    Input: nums = [3,7]
    Output: 12
 * ---------------------------------------------------------------------------------------------
 * Solution
   �D�ث�²��A�u����X�̤j����Ӥ��ۦP�ơA�æ^�Ǩ��1��ۭ������G�Y�i�C
 */

int maxProduct(int* nums, int numsSize){
    int max1[2] = {0}, max2 = 0;          // ���O�O�s��ӳ̤j����
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max1[0]) {
            max1[0] = nums[i];
            max1[1] = i;
        }
    }

    nums[max1[1]] = 0;                   // �����Ĥ@�ӳ̤j�ơA���קK�A�����A�ҥH�O�U����Шî����Ӽƭ�
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max2) {
            max2 = nums[i];
        }
    }
    return (max1[0] - 1) * (max2 - 1);
}

/*         faster             */
/**
 *  �Τ@�ӫ��ШӰ����ʡA������������}�ɶ��ӥ[�֫����B�檺�t�סC
 */
int maxProduct(int* nums, int numsSize){
    int max1 = 0, max2 = 0, pos;
    int *ptr = nums, i;              // �Ȧs����
    for (int i = 0; i < numsSize; i++, ptr++) {
        if (*ptr > max1) {
            max1 = *ptr;
            pos = i;
        }
    }
    ptr = nums;
    nums[pos] = 0;
    for (int i = 0; i < numsSize; i++, ptr++) {
        if (*ptr > max2) {
            max2 = *ptr;
        }
    }
    return (max1 - 1) * (max2 - 1);
}
