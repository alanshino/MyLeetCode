/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}
int* sortedSquares(int* A, int ASize, int* returnSize) {
    int *preturn=malloc(sizeof(int)*ASize),i=0;
    *returnSize=ASize;
    for (i=0;i<ASize;i++){
        *(preturn+i)=*(A+i)**(A+i);
    }
    qsort(preturn,ASize,sizeof(int),cmpfunc);
    return preturn;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* sortedSquares(int* A, int ASize, int* returnSize){
    int i=0,j=ASize-1;
    int k=ASize-1;
    int *B=(int *)calloc(ASize,sizeof(int));
    while(i<=j){
        if(abs(A[i])<abs(A[j])){
            B[k]=A[j]*A[j];
            j--;
        }
        else{
            B[k]=A[i]*A[i];
            i++;
        }
        k--;
    }
    *returnSize=ASize;
    return B;
}


/** Java

class Solution {
    public int[] sortedSquares(int[] A) {
        int n = A.length;
        int[] result = new int[n];
        int i = 0, j = n - 1;
        for (int p = n - 1; p >= 0; p--) {
            if (Math.abs(A[i]) > Math.abs(A[j])) {
                result[p] = A[i] * A[i];
                i++;
            } else {
                result[p] = A[j] * A[j];
                j--;
            }
        }
        return result;
    }
}

/** Python

class Solution(object):
    def sortedSquares(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        new = [x**2 for x in A]
        new.sort()
        return new

class Solution(object):
    def sortedSquares(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """

        return sorted([i**2 for i in A])
