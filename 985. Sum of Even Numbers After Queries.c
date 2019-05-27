/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesRowSize, int *queriesColSizes, int* returnSize) {
    int i, j, tmpSum;

    tmpSum = 0;
    for (j = 0; j < ASize; j++) {
       if (A[j] % 2 == 0) {
           tmpSum += A[j];
       }
    }

    int *queryAnswer = (int *)malloc(sizeof(int) * queriesRowSize);
    for (i = 0; i < queriesRowSize; i++) {

        if (A[queries[i][1]] % 2 == 0) {
            tmpSum -= A[queries[i][1]];
        }

        A[queries[i][1]] += queries[i][0];

        if (A[queries[i][1]] % 2 == 0) {
            tmpSum += A[queries[i][1]];
        }

        queryAnswer[i] = tmpSum;
    }

    *returnSize = queriesRowSize;
    return queryAnswer;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumEvenAfterQueries(int* A, int ASize, int** queries,
	int queriesRowSize, int *queriesColSizes, int* returnSize)
{
	int sum=0;
	*returnSize=queriesRowSize;
	int *result=malloc(queriesRowSize*sizeof(int));
	for(int i=0;i<ASize;i++)
		if(A[i]%2==0)
			sum+=A[i];
	for(int i=0;i<queriesRowSize;i++)
	{
		if(A[queries[i][1]]%2!=0 && queries[i][0]%2!=0)
			sum+=(A[queries[i][1]]+queries[i][0]);
		if(A[queries[i][1]]%2==0)
		{
			if(queries[i][0]%2!=0)
				sum-=A[queries[i][1]];
			else
				sum+=queries[i][0];
		}
		A[queries[i][1]]+=queries[i][0];
		result[i]=sum;
	}
	return result;
}

/** Java

class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int qlen = queries.length;
        int[] res = new int[qlen];
        int sum = 0;
        for (int var : A) {
            if ((var & 1) == 0) {
                sum += var;
            }
        }
        for (int i = 0; i < qlen; i++) {
            int index = queries[i][1];
            int val = queries[i][0];
            int anum = A[index];
            if ((anum & 1) == 0) {
                if ((val & 1) == 0) {
                    sum += val;
                } else {
                    sum -= anum;
                }
            } else {
                if ((val & 1) != 0) {
                    sum += anum + val;
                }
            }
            A[index] += val;
            res[i] = sum;
        }
        return res;
    }
}
