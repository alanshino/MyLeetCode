/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** A, int ASize, int* returnSize){
    char **preturn;                                     // ���t�^�ǭ�
    char **pa = malloc(sizeof(char *) * ASize);         // ���t�x�s�� , �ΨӰO���C�Ӧr��̪��r�ƥX�{����
    char a[26] = {0};
    int number = 0, min = 100, go = 0, tag = 0;
    for (int i = 0; i < ASize; i++) {
        pa[i] = calloc(26, sizeof(char));               // �� 26 ���Ӧr��
    }
    /*for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < 26; j++) {
            printf("%d ",pa[i][j]);
        }
        printf("\n");
    }*/
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < strlen(A[i]); j++) {
            pa[i][A[i][j] - 'a']++;
        }
    }
    preturn = malloc(sizeof(char *) * 100);             // �^�Ǥj�p�g��
    for (int i = 0; i < 100; i++) {
        preturn[i] = malloc(sizeof(char) * 2);
    }
    /*for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < 26; j++) {
            printf("%d ",pa[i][j]);
        }
        printf("\n");
    }
    /*for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < 26; j++) {
            if (pa[i][j] == 0) {
                go = 1;
                break;
            } else if (pa[i][j] < min) {
                min = pa[i][j];
            }
        }
        if (go) {
            min = 100;
        }else {
            number++;
        }
    }*/
    for (int i = 0; i < 26; i++) {                          // ���X 26 �Ӧr�� , �ȩ̀Ǳo�X�䦸��
        for (int j = 0; j < ASize; j++) {
            if (pa[j][i] == 0) {                            // �p�G�����@�����s , �����j�M�}�l�U�@�Ӧr��
                go = 1;
                break;
            }else if (pa[j][i] < min) {
                min = pa[j][i];                             // �ΨӤ���̤p���r���X�{����
            }
        }
        if (go) {
            go = 0;
        }else {
            for (int k = number; k < number + min; k++) {
                preturn[k][0] = i + 'a';
                preturn[k][1] = '\0';
            }
            number += min;
        }
        min = 100;
    }
    *returnSize = number;
    //printf("\n%d",*returnSize);
    return preturn;
}

// ���Ѫ��d��
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** A, int ASize, int* returnSize){
    char **preturn;
    int a[26] = {0};
    //int number = strlen(*A);
    int char_number = 0;
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < strlen(A[i]); j++) {
            a[A[i][j] - 97]++;
        }
    }
    for (int i = 0; i < 26; i++) {
        a[i] /= ASize;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] > 0) {
            char_number += a[i];
        }
    }
    preturn = malloc(sizeof(char *) * char_number);
    for (int i = 0; i < char_number; i++) {
        preturn[i] = malloc(sizeof(char) * 2);
    }
    char_number = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < a[i]; j++) {
            preturn[char_number][0] = i + 97;
            preturn[char_number][1] = '\0';
            char_number++;
        }
    }
    for (int i = 0; i < char_number; i++) {
        printf("%s ",preturn[i]);
    }
    *returnSize = char_number;
    return preturn;
}


// faster
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** A, int ASize, int* returnSize){
	int i = 0;
	char **row = (char**)malloc(100 * sizeof(char*));
	char *ptr, *ptr_A;
	*returnSize = 0;
	ptr_A = A[0];

	while (*ptr_A != '\0') {
		char tmp = *ptr_A;
		for (i=1; i < ASize; ++i) {
			if(ptr = strchr(A[i], tmp)) {
				A[i][ptr-A[i]] = '0';
			}
			else
				break;
		}
		if (i == ASize) {
			char *col = (char*)malloc(100*sizeof(char));
			row[*returnSize] = col;
			*row[*returnSize] = tmp;
			*(row[*returnSize]+1) = '\0';
            ++(*returnSize);
		}
		++ptr_A;
	}
	return row;
}

