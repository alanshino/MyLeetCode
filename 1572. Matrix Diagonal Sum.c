/* 1572. Matrix Diagonal Sum */
/**
 * Given a square matrix mat, return the sum of the matrix diagonals.
 * Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal
 * that are not part of the primary diagonal.
 * Example 1
    Input: mat = [[1,2,3],
                  [4,5,6],
                  [7,8,9]]
    Output: 25
    Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
    Notice that element mat[1][1] = 5 is counted only once.
 */

int diagonalSum(int** mat, int matSize, int* matColSize){
    int count = 0;
    int runtime = matSize;
    int start[2] = {0, 0};
    int end[2] = {0, matSize - 1};
    while (runtime) {
        count += mat[start[0]][start[1]];
        count += mat[end[0]][end[1]];
        start[0]++;
        start[1]++;
        end[0]++;
        end[1]--;
        runtime--;
    }

    if (matSize % 2) {
        count -= mat[matSize / 2][matSize / 2];
    }

    return count;
}
