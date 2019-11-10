/**
    Given n and m which are the dimensions of a matrix initialized by zeros and given an array indices where indices[i] = [ri, ci]. For each pair of [ri, ci] you have to increment all cells in row ri and column ci by 1.

    Return the number of cells with odd values in the matrix after applying the increment to all indices.
*/

int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize){
    int **pinit = malloc(sizeof(int *) * n);            // 分配記憶體空間並初始為0
    int odd = 0;
    for (int i = 0; i < n; i++) {
        pinit[i] = calloc(m, sizeof(int));
    }
   // printf("%d %d", indicesSize, *indicesColSize);
    for (int i = 0; i < indicesSize; i++) {             // 依序走訪
        for (int j = 0; j < m; j++) {                   // row
            pinit[indices[i][0]][j]++;
        }
        for (int j = 0; j < n; j++) {                   // col
            pinit[j][indices[i][1]]++;
        }
        // break;
    }
    for (int i = 0; i < n; i++) {                       // 找出奇數
        for (int j = 0; j < m; j++) {
            if (pinit[i][j] % 2) {
                odd++;
            }
        }
    }
    return odd;
}

