/** C

int compar(const void * a, const void * b);
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int cost_A = 0 ,i = 0, sum = 0;
    int *diff_array = malloc(sizeof(int)*costsSize);
    //printf("%d",*costsColSize);
    for (i = 0; i < costsSize; i++) {
        sum += costs[i][0];
        diff_array[i] = costs[i][0] - costs[i][1];
    }
    qsort(diff_array, costsSize, sizeof(int), compar);
    for (i = costsSize-1; i >= costsSize/2; i--) {
        sum -= diff_array[i];
    }
    return sum;
}

int compar(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

/** C

int cmp(int* *a,int* *b){
    int ta = (*a)[0] - (*a)[1];
    int tb = (*b)[0] - (*b)[1];

    return ta-tb;
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int ans = 0;

    qsort(costs, costsSize, sizeof(int *), cmp);

    for (int n = 0; n < costsSize/2; n++) ans += costs[n][0] + costs[costsSize -n-1][1];

    return ans;
}

/** C

int comp(void* a,void* b){
    int* v1=*(int**)a;
    int* v2=*(int**)b;
    return v2[1]-v2[0]-v1[1]+v1[0];
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    qsort(costs,costsSize,sizeof(int*),&comp);
    int half=costsSize>>1;
    int ret=0;
    for(int i=0;i<half;++i){
        ret+=costs[i][0];
    }
    for(int i=half;i<costsSize;++i){
        ret+=costs[i][1];
    }
    return ret;
}

/** Java

class Solution {

    public int twoCitySchedCost(int[][] costs) {
        int res = 0;
        for (int i = 0; i < costs.length; i++) {
            res += costs[i][0];
        }

        int[] diff = new int[costs.length];
        for (int i = 0; i < costs.length; i++) {
            diff[i] = costs[i][1] - costs[i][0];
        }

        int p = quickselect(diff, 0, costs.length - 1, costs.length / 2);
        for (int i = 0; i <= p; i++) {
            res += diff[i];
        }
        return res;
    }

    public int quickselect(int[] diff, int lo, int hi, int n) {
        // System.out.printf("lo: %d, hi: %d, n: %d\n", lo, hi, n);
        if (hi - lo + 1 <= n) {
            return hi;
        }
        int p = partition(diff, lo, hi);
        int left = p - lo + 1;
        if (left == n) {
            return p;
        } else if (left < n) {
            return quickselect(diff, p + 1, hi, n - left);
        } else {
            return quickselect(diff, lo, p, n);
        }
    }

    public int partition(int[] diff, int lo, int hi) {
        int pivot = diff[(lo + hi) >>> 1];
        int i = lo - 1;
        int j = hi + 1;
        while (true) {
            while (diff[++i] < pivot) {

            }
            while (diff[--j] > pivot) {

            }
            if (i >= j) {
                return j;
            }
            swap(diff, i, j);
        }
    }

    public void swap(int[] diff, int i, int j) {
        int t = diff[i];
        diff[i] = diff[j];
        diff[j] = t;
    }

}

*/
