int* constructRectangle(int area, int* returnSize) {
    *returnSize=2;
    int *pint=malloc(sizeof(int)*(*returnSize));
    int x=(int)ceil(sqrt(area));
    int y=0;
    while ((area%x)!=0){
        x++;
    }
    y=area/x;
    *(pint+0)=x;
    *(pint+1)=y;
    return pint;
}
