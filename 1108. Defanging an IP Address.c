char * defangIPaddr(char * address){
    int index = 0;
    int return_size = strlen(address);                    // �T�{���^�Ǫ��O����j�p
    char *preturn = NULL;
    preturn = malloc(sizeof(char) * (return_size + 7));
    while (*address) {                                    // �̧Ǩ��X IP �r��
        if (*address == '.') {
            preturn[index++] = '[';
            preturn[index++] = '.';
            preturn[index++] = ']';
            address++;
        }
        preturn[index++] = *address++;
    }
    preturn[index++] = '\0';
    return preturn;
}

/** faster **/

char * defangIPaddr(char * address){
    int index = 0;
    char *preturn = malloc(sizeof(char) * 22);           // �������t�̤j�i��ϥΪ��O����Ŷ�
    while (*address) {
        if (*address == '.') {
            preturn[index++] = '[';
            preturn[index++] = '.';
            preturn[index++] = ']';
            address++;
        }
        preturn[index++] = *address++;
    }
    preturn[index++] = '\0';
    return preturn;
}



