/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    int *preturn = malloc(sizeof(int) * n);
    int counter = 0;
    *returnSize = n;
    if (n % 2) {                                   // 這裡判斷奇數 OR 偶數
        for (int i = 0; i < n / 2 + 1; i++) {
            if (i == 0) {
                preturn[counter++] = 0;
            }else {
                preturn[counter++] = i;
                preturn[counter++] = -i;
            }
        }
    }else {
        for (int i = 0; i < n / 2; i++) {
            preturn[counter++] = i + 1;
            preturn[counter++] = -(i + 1);
        }
    }
    return preturn;
}

/**
 * 題目給定一個變數n並要求需要建立一個陣列來儲存相同的數值，而且總和須為 0 並且不能出現重複的數值
 * 因為總和要為 0 所以一個負數 i 與正數 i 相加剛好可以抵銷 (適用在為偶數個時)
 * 如果遇到 n 為奇數時就增加一個0值來填補空缺
 */
