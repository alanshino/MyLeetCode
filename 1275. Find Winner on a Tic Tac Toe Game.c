char * tictactoe(int** moves, int movesSize, int* movesColSize){
    char **ptrTTT = malloc(sizeof(char *) * 3);
    int record = 0;
    for (int i = 0; i < 3; i++) {
        ptrTTT[i] = calloc(3, sizeof(char));                  // ���� 3 * 3 ��array�K��ʼ�� 0
    }
    for (int i = 0; i < movesSize; i++) {                     // ���}ĿҪ���λ�ý�������(��int 1 OR int 2��������)

        if (i % 2) {
            ptrTTT[moves[i][0]][moves[i][1]] = 1;
        }else {
            ptrTTT[moves[i][0]][moves[i][1]] = 2;
        }

    }
    /*
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", ptrTTT[i][j]);
        }
        printf("\n");
    }
    */

    if (movesSize < 5) {               // ������δ�����[��
        return "Pending";
    }

    if (ptrTTT[0][0] == ptrTTT[0][1] && ptrTTT[0][1] == ptrTTT[0][2] && ptrTTT[0][0] && ptrTTT[0][1] && ptrTTT[0][2]) {

        return (ptrTTT[0][0] == 2)?"A":"B";
    }else if (ptrTTT[0][0] == ptrTTT[1][0] && ptrTTT[1][0] == ptrTTT[2][0] && ptrTTT[0][0] && ptrTTT[1][0] && ptrTTT[2][0]) {

        return (ptrTTT[0][0] == 2)?"A":"B";
    }else if (ptrTTT[0][0] == ptrTTT[1][1] && ptrTTT[1][1] == ptrTTT[2][2] && ptrTTT[0][0] && ptrTTT[1][1] && ptrTTT[2][2]) {

        return (ptrTTT[0][0] == 2)?"A":"B";
    }else if (ptrTTT[0][1] == ptrTTT[1][1] && ptrTTT[1][1] == ptrTTT[2][1] && ptrTTT[0][1] && ptrTTT[1][1] && ptrTTT[2][1]) {

        return (ptrTTT[0][1] == 2)?"A":"B";
    }else if (ptrTTT[0][2] == ptrTTT[1][2] && ptrTTT[1][2] == ptrTTT[2][2] && ptrTTT[0][2] && ptrTTT[1][2] && ptrTTT[2][2]) {

        return (ptrTTT[0][2] == 2)?"A":"B";
    }else if (ptrTTT[1][0] == ptrTTT[1][1] && ptrTTT[1][1] == ptrTTT[1][2] && ptrTTT[1][0] && ptrTTT[1][1] && ptrTTT[1][2]) {

        return (ptrTTT[1][0] == 2)?"A":"B";
    }else if (ptrTTT[2][0] == ptrTTT[1][1] && ptrTTT[1][1] == ptrTTT[0][2] && ptrTTT[2][0] && ptrTTT[1][1] && ptrTTT[0][2]) {

        return (ptrTTT[2][0] == 2)?"A":"B";
    }else if (ptrTTT[2][0] == ptrTTT[2][1] && ptrTTT[2][1] == ptrTTT[2][2] && ptrTTT[2][0] && ptrTTT[2][1] && ptrTTT[2][2]) {

        return (ptrTTT[2][0] == 2)?"A":"B";
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ptrTTT[i][j])
                record++;
        }
    }

    if (record == 9)              // ������x�o�˄����ҟo�ظ�ɷ��ô������
        return "Draw";
    else
        return "Pending";
}
