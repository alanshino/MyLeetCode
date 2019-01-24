int maxIncreaseKeepingSkyline(int** grid, int gridRowSize, int *gridColSizes) {
    int i,j,max=0,total=0,add1,add2;
    int **preturn=malloc(sizeof(int*)*(gridRowSize+1));             // だ皌pointer to int*
    for (i=0;i<gridRowSize+1;i++){
        *(preturn+i)=calloc(*gridColSizes+1,sizeof(int));           // だ皌︽int
    }
    for (i=0;i<gridRowSize;i++){
        for (j=0;j<*gridColSizes;j++){
            if (*(*(grid+i)+j)>max){
                max=*(*(grid+i)+j);                                 // т–い程
            }
            *(*(preturn+i+1)+j+1)=*(*(grid+i)+j);                   // 硈盿ЧΘ穝皚
        }
        *(*(preturn+i+1)+0)=max;
        max=0;
    }
    for (i=0;i<*gridColSizes;i++){
        for (j=0;j<gridRowSize;j++){
            if (*(*(grid+j)+i)>max){
                max=*(*(grid+j)+i);                                 // т–︽い程
            }
        }
        *(*(preturn+0)+i+1)=max;
        max=0;
    }
    /*for (i=0;i<gridRowSize+1;i++){
        for (j=0;j<*gridColSizes+1;j++){
            printf("%d ",*(*(preturn+i)+j));
        }
        printf("\n");
    }*/
    for (i=1;i<gridRowSize+1;i++){
        for (j=1;j<*gridColSizes+1;j++){
            add1=*(*(preturn+0)+j);                                 // City Skyline 惠璶蛤––︽暗ゑ耕,糤ぃ禬筁程
            add2=*(*(preturn+i)+0);
            if (add1>add2){
                total+=add2-*(*(preturn+i)+j);                      // total 癘计糤ぶ
            }else{
                total+=add1-*(*(preturn+i)+j);
            }
        }
    }
    return total;
}

/** Python
class Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row, col = map(max, grid), map(max, zip(*grid))
        return sum(min(i, j) for i in row for j in col) - sum(map(sum, grid))
*/
/** Java
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0] == null || grid[0].length == 0) {
            return 0;
        }
        int m = grid.length;
        int n = grid[0].length;
        int[] lrMax = new int[m];
        int[] udMax = new int[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                lrMax[i] = Math.max(lrMax[i], grid[i][j]);
                udMax[j] = Math.max(udMax[j], grid[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res += Math.min(lrMax[i], udMax[j]) - grid[i][j];
            }
        }
        return res;
    }
}
*/
