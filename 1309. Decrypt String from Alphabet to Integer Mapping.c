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
    while (*ptemp) {                                        // ���P�_�r���`�ƨýT�{#�X�{������
        if (*ptemp == '#') {
            index++;
        }
        count++;
        ptemp++;
    }
    ptemp = malloc(sizeof(char) * (count - index * 2 + 1)); // �N�`�r�Ʀ���#*2 �[1���O�d�^�Ǥ��׵���'\0'
    count = 0;

    while (*s) {
        if (index) {
            if (*(s + 2) == '#') {
                count += (*s - '0') * 10;               // �b���B�P�_�O�_��#�r��
                count += *(s + 1) - '0';                // ���N�r���ର��ƭ�
                ptemp[indexReturn++] = count + 96;      // �ഫ�覡��ASCII�s�X
                s += 3;
                index--;
                count = 0;
            }else {
                ptemp[indexReturn++] = *s + 48;         // �D#�r�ūh����ƭȪ����ഫ�Y�i
                s++;
            }
        }else {
            ptemp[indexReturn++] = *s + 48;
            s++;
        }
    }

    ptemp[indexReturn] = '\0';                         // ��W�r��׵��ŧY�i�^��

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
