/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    int *preturn = malloc(sizeof(int) * n);
    int counter = 0;
    *returnSize = n;
    if (n % 2) {                                   // �@�e�Д��攵 OR ż��
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
 * �}Ŀ�o��һ��׃��n�KҪ����Ҫ����һ����Ё탦����ͬ�Ĕ�ֵ�����ҿ���횞� 0 �K�Ҳ��ܳ��F���}�Ĕ�ֵ
 * ��鿂��Ҫ�� 0 ����һ��ؓ�� i �c���� i ��ӄ��ÿ��Ե��N (�m���ڞ�ż�����r)
 * ������� n ���攵�r������һ��0ֵ�����a��ȱ
 */
