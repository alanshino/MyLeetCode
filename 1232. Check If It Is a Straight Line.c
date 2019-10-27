bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    double slopeX = coordinates[0][0] - coordinates[1][0];
    double slopeY = coordinates[0][1] - coordinates[1][1];
    double slopeM;
    int vertical = 0;                                                 // �e�����ܼƥΨӰO���ײv����
    for (int i = 0; i < coordinatesSize - 1; i++) {
        if (coordinates[i][0] == coordinates[i + 1][0]) {             // �ΨӧP�_�O�_�������u,�����u���ײv�����w�q
            vertical = 1;
            break;
        }
    }
    if (vertical) {                                                   // �ϥΨ�ؤ覡�p��ײv,�H�קK�����u(������0)
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
