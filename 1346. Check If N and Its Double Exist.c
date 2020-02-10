/**
Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :

    i != j
    0 <= i, j < arr.length
    arr[i] == 2 * arr[j]

�D�ص��w��ư}�Carr�A���ˬd�O�_�s�b��Ӿ��N�MM�A�H��N��M���⭿�]�YN = 2 * M�^�C

Example :
Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.

Input: arr = [7,1,14,11]
Output: true
Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.

Input: arr = [3,1,7,11]
Output: false
Explanation: In this case does not exist N and M, such that N = 2 * M.
*/


bool checkIfExist(int* arr, int arrSize){

    for (int i = 0; i < arrSize; i++) {              // �ϥα_��loop�ӧP�w
        for (int j = 0; j < arrSize; j++) {
            if (i == j) continue;                    // ���L�ۦP����
            if (arr[j] * 2 == arr[i]) return 1;      // �p�G����@������double�ŦX����Ϧ^��TRUE
        }
    }

    return 0;
}
