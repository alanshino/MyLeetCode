/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char* S, int* returnSize) {
    int i=0;
    int line=1,unit=0,length=100;                     // 每列100空間
    int *preturn=malloc(sizeof(int)*2);
    *returnSize=2;
    while (*S){
        if (length-*(widths+*S-97)>=0){               //  剩餘空間減去這個字元需求空間
            length-=*(widths+*S-97);                  //  足夠直接遞減
            S++;
        }else{
            line++;                                   //  不夠開下一列
            length=100;                               //  重新分配到100空間
        }
    }
    *(preturn+0)=line;                                //  紀錄使用列數
    *(preturn+1)=100-length;                          //  記錄目前使用到的行數,因為採用減法(代表這列還有多少空間),所以要用100空間來算
    return preturn;
}
