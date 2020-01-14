/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    int *preturn = NULL;
    int total = 0;
    int index = 0;
    for (int i = 0; i < numsSize; i += 2) {        // ���T�{�n���t���O����Ŷ��j�p
        total += nums[i];
    }
    preturn = malloc(sizeof(int) * total);
    *returnSize = total;
    for (int i = 0; i < numsSize; i += 2) {         // �N�ƭȨ̫��w�ӼƩ�J
        for (int j = 0; j < nums[i]; j++) {
            preturn[index++] = nums[i + 1];
        }
    }
    return preturn;
}

/**
 *  �D�ص��w�@�� array �̭��x�s���ƭȬ����諸�A�Ĥ@�Ӫ�ܭӼơA�ĤG�Ӫ�ܼƭȡC
 *  ������^�� array
 *  Example:
 *  Input: nums = [1,2,3,4]
 *  Output: [2,4,4,4]
 *  Explanation: The first pair [1,2] means we have freq = 1 and val = 2 so we generate the array [2].
 *  The second pair [3,4] means we have freq = 3 and val = 4 so we generate [4,4,4].
 *  At the end the concatenation [2] + [4,4,4] is [2,4,4,4].
 */
