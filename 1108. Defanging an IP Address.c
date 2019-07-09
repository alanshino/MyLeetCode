char * defangIPaddr(char * address){
    int index = 0;
    int return_size = strlen(address);                    // 確認須回傳的記憶體大小
    char *preturn = NULL;
    preturn = malloc(sizeof(char) * (return_size + 7));
    while (*address) {                                    // 依序走訪 IP 字串
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
    char *preturn = malloc(sizeof(char) * 22);           // 直接分配最大可能使用的記憶體空間
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



