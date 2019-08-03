char * getHint(char * secret, char * guess){
    int bull = 0, cow = 0;
    int a1[10] = {0};                    // 儲存 secret 0 - 9 的個數
    int a2[10] = {0};                    // 儲存 guess 0 - 9 的個數
    int offset = 0, temp, cowoffset;     // 紀錄偏移量 , 暫存值 , 因為有 A , B 兩個分隔所以需要第二個偏移量
    char *preturn = secret;              // Pointer 會移動 , 所以分別保存
    char *pguess = guess;
    while (*preturn) {
        if (*preturn == *pguess) {
            bull++;                      // 先計算 bull 的數量 (位置 , 數值都需一致)
            *preturn = '*';              // 紀錄後更改值 , 避免之後 cow 取用同一個數
            *pguess = '*';
        }
        preturn++;
        pguess++;
    }
    preturn = secret;
    pguess = guess;
    while (*preturn && *pguess) {        // 計算 cow 的數量 , 只要數值一樣
        if (*preturn != '*') {
            a1[*preturn - '0']++;
            a2[*pguess - '0']++;
        }
        preturn++;
        pguess++;
    }
    for (int i = 0; i < 10; i++) {
        if (a1[i] && a2[i]) {
            cow += (a1[i] > a2[i])? a2[i] : a1[i];  // 兩個 input 中的數值分別比較 , 留下較小的數
        }
    }
    preturn = malloc(sizeof(char) * 100);
  /*  if (!bull && !cow) {
        preturn[offset++] = '0';
        preturn[offset++] = 'A';
        preturn[offset++] = '0';
        preturn[offset++] = 'B';
        preturn[offset] = '\0';
        return preturn;
    }  */
    if (!bull)
        preturn[offset++] = '0';
    else
        while (bull) {
            preturn[offset++] = bull % 10 + '0';
            bull /= 10;
        }
    if (offset > 1) {
        for (int i = 0, j = offset - 1; i < offset && j > 0; i++, j--) {   // 因為放入後會相反 , 所以須反轉
            temp = preturn[i];
            preturn[i] = preturn[j];
            preturn[j] = temp;
        }
    }
    preturn[offset++] = 'A';
    cowoffset = offset;
    if (!cow)
        preturn[offset++] = '0';
    else
        while (cow) {
            preturn[offset++] = cow % 10 + '0';
            cow /= 10;
        }
    if ((offset - cowoffset) > 1) {
        for (int i = cowoffset, j = offset - 1; i < offset && j > cowoffset; i++, j--) {
            temp = preturn[i];
            preturn[i] = preturn[j];
            preturn[j] = temp;
        }
    }
    preturn[offset++] = 'B';
    // printf("%d %d", bull, cow);
    preturn[offset] = '\0';
    return preturn;
}


/** C

char* getHint(char* secret, char* guess)
{
    int len=strlen(secret);
    int bulls=0;
    int* secretMap=(int*)calloc(10,sizeof(int));
    int* guessMap=(int*)calloc(10,sizeof(int));
    for(int i=0;i<len;i++)
    {
        if(secret[i]==guess[i])
        {
            bulls++;
        }
        else
        {
            secretMap[secret[i]-'0']++;
            guessMap[guess[i]-'0']++;
        }
    }
    int cows=0;
    for(int i=0;i<10;i++)
    {
        cows+=secretMap[i]>guessMap[i]?guessMap[i]:secretMap[i];
    }
    char* ret=(char*)malloc(sizeof(char)*10);
    sprintf(ret,"%dA%dB",bulls,cows);
    return ret;
}

*/

