/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** A, int ASize, int* returnSize){
    char **preturn;                                     // 分配回傳值
    char **pa = malloc(sizeof(char *) * ASize);         // 分配儲存值 , 用來記錄每個字串裡的字數出現次數
    char a[26] = {0};
    int number = 0, min = 100, go = 0, tag = 0;
    for (int i = 0; i < ASize; i++) {
        pa[i] = calloc(26, sizeof(char));               // 有 26 六個字母
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
    preturn = malloc(sizeof(char *) * 100);             // 回傳大小寫死
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
    for (int i = 0; i < 26; i++) {                          // 走訪 26 個字母 , 並依序得出其次數
        for (int j = 0; j < ASize; j++) {
            if (pa[j][i] == 0) {                            // 如果有任一項為零 , 直接搜尋開始下一個字母
                go = 1;
                break;
            }else if (pa[j][i] < min) {
                min = pa[j][i];                             // 用來比較最小的字母出現次數
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

// 失敗的範例
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

