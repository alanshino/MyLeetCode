/**
 *
 * 1309. Decrypt String from Alphabet to Integer Mapping
 *
 */
char * freqAlphabets(char * s){
    int count = 0;
    char *ptemp = s;
    int index = 0;
    int indexReturn = 0;
    while (*ptemp) {                                        // 先判斷字串總數並確認#出現的次數
        if (*ptemp == '#') {
            index++;
        }
        count++;
        ptemp++;
    }
    ptemp = malloc(sizeof(char) * (count - index * 2 + 1)); // 將總字數扣除#*2 加1為保留回傳之終結符'\0'
    count = 0;

    while (*s) {
        if (index) {
            if (*(s + 2) == '#') {
                count += (*s - '0') * 10;               // 在此處判斷是否有#字符
                count += *(s + 1) - '0';                // 先將字元轉為整數值
                ptemp[indexReturn++] = count + 96;      // 轉換方式為ASCII編碼
                s += 3;
                index--;
                count = 0;
            }else {
                ptemp[indexReturn++] = *s + 48;         // 非#字符則為單數值直接轉換即可
                s++;
            }
        }else {
            ptemp[indexReturn++] = *s + 48;
            s++;
        }
    }

    ptemp[indexReturn] = '\0';                         // 填上字串終結符即可回傳

    return ptemp;
}

/**
 char * freqAlphabets(char * s){
    int len = strlen(s);
    int num=0,temp=0;
    int i,idx=0;
    char* result = (char*)malloc(len);

    for(i=len-1;i>=0;)
    {
        if(s[i]=='#')
        {
            num = (s[i-2]-'0')*10 + s[i-1]-'0'-1;
            result[idx++] = num + 'a';
            i -= 3;
        }
        else
        {
            num = s[i]-'0'-1;
            result[idx++] = num + 'a';
            i -= 1;
        }
    }
    result[idx] = '\0';

    i=0;
    while(i<idx)
    {
        temp = result[i];
        result[i] = result[idx-1];
        result[idx-1] = temp;
        i++;
        idx--;
    }

    return result;
}

*/
