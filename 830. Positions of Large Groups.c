/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char* S, int** columnSizes, int* returnSize) {
    int a=strlen(S),i=0,count=0,j=0,counter=0;          // 記錄總共有幾個
    char flip_flop;
    int array[1000]={0};                                // 紀錄每個起始與終止
    char *pc=NULL;
    int **preturn=NULL;
    for (i=0;i<a-2;i++){
        if (*(S+i)==*(S+i+1)&&*(S+i)==*(S+i+2)){        // 判斷是否滿三個
            pc=S+i;                                     // pc is a pointer to char to remember start location
            flip_flop=*(S+i);                           // remember the start value
            array[counter]=i;                           // remember the location
            counter++;
            while (*pc==flip_flop){
                pc++;
                j++;                                    // 判斷連續幾個,及最後位置到哪
            }
            array[counter]=i+j-1;
            counter++;
            i+=j-1;
            j=0;                                        // 歸零
        }
    }
    /*for (i=0;i<counter;i++){
        printf("%d ",array[i]);
    }*/
    preturn=malloc(sizeof(int *)*counter/2);            // 分配記憶體位置pointer to int *
    for (i=0;i<counter/2;i++){
        *(preturn+i)=malloc(sizeof(int)*2);             // 分配記憶體位置pointer to pointer to int
    }
    *returnSize=counter/2;                              // returnSize is counter total/2
    for (i=0;i<counter/2;i++){
        *columnSizes=malloc(sizeof(int)*counter/2);     // *columnSizes array must be malloced
    }
    for (i=0;i<counter/2;i++){
        *(*(columnSizes)+i)=2;                          // 每行兩個元素是固定的
    }
    for (i=0;i<counter/2;i++){
        for (j=0;j<2;j++){
            *(*(preturn+i)+j)=array[count];             // 將array紀錄值循序放入pointer to pointer to int
            count++;
        }
    }
    return preturn;
}

/** Java
class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> res = new ArrayList<>();
        if (S == null || S.length() == 0) {
            return res;
        }
        int start = 0;
        for (int i = 1; i < S.length(); i++) {
            if (S.charAt(i) != S.charAt(start)) {
                if (i - start >= 3) {
                    res.add(Arrays.asList(start, i - 1));
                }
                start = i;
            }
        }
        if (S.length() - start >= 3) {
            res.add(Arrays.asList(start, S.length() - 1));
        }
        return res;
    }
}
*/
/** Python
class Solution(object):
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        n = len(S)

        start = 0
        res = []
        for i in range(1, n):
            if S[i] != S[i-1]:
                length = (i - 1) - start + 1
                if length >= 3:
                    res.append([start, i-1])

                start = i

        if (n-start) >= 3:
            res.append([start, n-1])

        return res
*/
