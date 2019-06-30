/**
    Input: 5
    Output:
    [
             [1],
            [1,1],
           [1,2,1],
          [1,3,3,1],
         [1,4,6,4,1]
    ]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **preturn = NULL;
   /* int **b = malloc(sizeof(int *) * 2);
    for (int i = 0; i < 2; i++) {
        b[i] = malloc(sizeof(int) * (i + 1));
    }
    b[0][0] = 1;
    b[1][0] = 1;
    b[1][1] = 1; */
    *returnSize = 0;                                  // �S�����󤸯�
    if (!numRows) {
        preturn = malloc(sizeof(int *));
        return preturn;
    }
    if (numRows == 1) {
        // return {{1}};
        preturn = malloc(sizeof(int *) * 1);          // 1�Ӥ������P {{1}}
        *preturn = malloc(sizeof(int));
        **preturn = 1;
        *returnSize = numRows;
        *returnColumnSizes = malloc(sizeof(int) * 1);
        **returnColumnSizes = numRows;
        return preturn;
    }
   /* if (numRows == 2) {
        // return {{1},{1,1}};
        *returnSize = 2;
        returnColumnSizes = malloc(sizeof(int) * 2);
        for (int i = 0; i < 2; i++)
            returnColumnSizes[i] = i + 1;

        return b;
    } */
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int) * numRows);                       // �j�� 1 �Ӥ���
    for (int i = 0; i < numRows; i++)                                         // �ѩ��D�ش��Ѥ@�ӫ��Ъ���m�@���^�ǯ���
        (*returnColumnSizes)[i] = i + 1;                                      // �ҥH��J Col ���Ȯɶ��`�N���Ш��ȱo�u����
    preturn = malloc(sizeof(int *) * numRows);
    for (int i = 0; i < numRows; i++) {
        preturn[i] = malloc(sizeof(int) * (i + 1));
    }
    preturn[0][0] = 1;
    for (int i = 1; i < numRows; i++) {                                       // ����V�W��������ӭ� , �ۥ[���J
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                preturn[i][j] = 1;
            }else {
                preturn[i][j] = preturn[i - 1][j - 1] + preturn[i - 1][j];
            }
        }
    }
    return preturn;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void gen(int **ret,int numRows,int i,int** returnColumnSizes)
{
    if(i>=numRows) return;
    ret[i]=malloc(sizeof(int)*(i+1));
    ret[i][0]=1;
    ret[i][i]=1;
    *(*returnColumnSizes+i)=i+1;
    for(int j=1;j<i;j++)
    ret[i][j]=ret[i-1][j-1]+ret[i-1][j];
    gen(ret,numRows,++i,returnColumnSizes);

}

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **ret=malloc(sizeof(int*)*numRows);
    *returnColumnSizes=malloc(sizeof(int)*numRows);
    gen(ret,numRows,0,returnColumnSizes);
    *returnSize=numRows;
    return ret;
}
