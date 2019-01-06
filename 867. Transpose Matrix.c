/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    int i=0,j=0,k=0,c=0;
    int **myrowcol=malloc(sizeof(int*)**AColSizes);  // 分配指向COL的pointer
    *returnSize=*AColSizes;
    *columnSizes=(int *)malloc(sizeof(int)*(*AColSizes));
    for(i=0;i<*AColSizes;i++){          // ***********
        columnSizes[0][i]=ARowSize;
    }
    for (i=0;i<*AColSizes;i++){
        *(myrowcol+i)=malloc(sizeof(int)*ARowSize);   // 分配指向ROW的pointer
    }
    for (i=0,k=0;i<ARowSize;i++){                     // 取指標的步長ROW
        for (j=0;j<*AColSizes;j++){                   // 取指標的步長COL
            *(*(myrowcol+j)+i)=*(*(A+i)+j);           // 一個是取ROW再取COL 轉至為取COL再取ROW
        }
        printf("\n");
    }
    return myrowcol;
}
