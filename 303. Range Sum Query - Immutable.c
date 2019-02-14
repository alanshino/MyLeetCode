typedef struct {
    int data;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj=malloc(sizeof(NumArray)*numsSize);
    for (int i=0;i<numsSize;i++) {
        (obj+i)->data=*(nums+i);
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int returnint=0;
    for (int n=i;n<=j;n++) {
        returnint+=(*(obj+n)).data;
    }
    return returnint;
}

void numArrayFree(NumArray* obj) {
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */
/** C faster
typedef struct {
    int *BIT;
} NumArray;

int getSum(int *BIT, int i)
{
    i = i + 1;
    int sum = 0;
    while(i > 0){
        sum += BIT[i];
        i -= (i & (-i));
    }
    return sum;
}

void UpdateBIT(int *BIT, int val, int i, int n)
{
    int index = i + 1;
    while(index <= n){
        BIT[index] += val;
        index += (index & (-index));
    }
}

int *constructBITree(int *nums, int n)
{
	int *BIT = calloc(n + 1, sizeof(int));
	for(int i = 0; i < n; i++)
		UpdateBIT(BIT, nums[i], i, n);

	return BIT;
}

NumArray* numArrayCreate(int* nums, int numsSize) {
    if(numsSize == 0) return NULL;
    NumArray *na = (NumArray*)malloc(sizeof(NumArray));
    na->BIT = constructBITree(nums, numsSize);

    return na;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    return getSum(obj->BIT, j) - getSum(obj->BIT, i - 1);
}

void numArrayFree(NumArray* obj) {
    if(obj && obj->BIT){
        free(obj->BIT);
        free(obj);
    }
}
*/
