/** C

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* A, int ASize, int* returnSize) {
    bool *preturn = malloc(sizeof(bool)*ASize);
    int i=0 , counter = 0;
    *returnSize=ASize;
    for (i=0;i<ASize;i++) {
        counter = (counter*2 + *(A+i))%5;
        //printf("%d ",counter);
        if (counter==0)
            *(preturn+i)=1;
        else
            *(preturn+i)=0;
    }
/*  printf("\n");
    for (i=0;i<ASize;i++) {
        printf("%d ",*(preturn+i));
    }*/
    return preturn;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    bool* res = malloc(ASize*sizeof(bool));
    int tmp = 0;
    for(int i=0; i<ASize; i++)
        res[i] = (tmp = (A[i] + (tmp<<1)) % 5) ? false : true;
    return res;
}

bool* prefixesDivBy5(int* A, int ASize, int* returnSize)
{
    int value = 0;
    bool* result = (bool*)malloc(sizeof(bool) * ASize);
    for (int i = 0; i <= ASize - 1; i++)
    {
        value = (value * 2 + A[i]) % 5;
        result[i] = value ? false : true;
    }
    *returnSize = ASize;
    return result;
}

/** Javascript  */

/**
 * @param {number[]} A
 * @return {boolean[]}
 */
var prefixesDivBy5 = function (A) {
    if (A == null) return A;
    const r = new Array(A.length)
    let total = 0
    for (let i = 0; i < A.length; i++) {
        total = ((total << 1) + A[i]) % 5
        r[i] = total === 0
    }
    return r
};

/**
 * @param {number[]} A
 * @return {boolean[]}
 */
var prefixesDivBy5 = function(A) {
  let res = [];
  A.reduce((acc, cur) => {
      acc = (acc*2 + cur)%5
      res.push(acc === 0);
      return acc;
    }, 0);
  return res;
};
