bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    double slopeX = coordinates[0][0] - coordinates[1][0];
    double slopeY = coordinates[0][1] - coordinates[1][1];
    double slopeM;
    int vertical = 0;                                                 // 前面的變數用來記錄斜率之值
    for (int i = 0; i < coordinatesSize - 1; i++) {
        if (coordinates[i][0] == coordinates[i + 1][0]) {             // 用來判斷是否為垂直線,垂直線之斜率為未定義
            vertical = 1;
            break;
        }
    }
    if (vertical) {                                                   // 使用兩種方式計算斜率,以避免垂直線(分母為0)
        slopeM = slopeX / slopeY;
        for (int i = 1; i < coordinatesSize - 1; i++) {
            if (slopeM != (coordinates[i][0] - coordinates[i + 1][0]) / (coordinates[i][1] - coordinates[i + 1][1])) {
                return 0;
            }
        }
    }else {
        slopeM = slopeY / slopeX;
        for (int i = 1; i < coordinatesSize - 1; i++) {
            if (slopeM != (coordinates[i][1] - coordinates[i + 1][1]) / (coordinates[i][0] - coordinates[i + 1][0])) {
                return 0;
            }
        }
    }
    return 1;
}
