/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize) {    // very slow
    int i=0,j=0,temp=0;
    *returnSize=ASize;
    for (i=0;i<ASize;i++){
        for (j=0;j<ASize;j++){
            if (*(A+i)%2==0 && *(A+j)%2==1){
                temp=*(A+j);
                *(A+j)=*(A+i);
                *(A+i)=temp;
            }
        }
    }
    return A;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize) {    // the faster
    int *preturn=NULL;
    int i,j,k;
    *returnSize=ASize;
    preturn=malloc(sizeof(int)**returnSize);
    for(i=0, j=0, k=ASize-1; i < ASize; i++){
        if((*(A+i))%2==0){
            *(preturn+j++) = *(A+i);
            //j++;
        }
        else{
            *(preturn+k--) = *(A+i);
            //k--;
        }
    }
    return preturn;
}

