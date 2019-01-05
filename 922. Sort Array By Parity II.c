/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
    int i=0,j=0,k=0;
    *returnSize=ASize;
    int *podd=malloc(sizeof(int)**returnSize/2);
    int *peven=malloc(sizeof(int)**returnSize/2);
    for (i=0;i<*returnSize;i++){
        if (*(A+i)%2){
            *(podd+j)=*(A+i);
            j++;
        }else{
            *(peven+k)=*(A+i);
            k++;
        }
    }
    j=0;
    k=0;
    for (i=0;i<*returnSize;i++){
        if (i%2==1){
            *(A+i)=*(podd+j);
            j++;
        }else{
            *(A+i)=*(peven+k);
            k++;
        }
    }
    return A;
}
