bool isSubsequence(char * s, char * t){
    int num_s = strlen(s);               // s �O�l�r�� , �p��X�����
    int count = 0;                       // �ΨӧP�_�۲Ŧr�����ƥ�
    while (*t) {
        if (*s == *t) {                  // �p�G *s ���r���P *t �۵�
            count++;
            s++;                         // s ���в���
        }
        t++;                             // t ���еL�׬O�_�۵��ҷ|����
    }
    if (count == num_s)
        return 1;
    else
        return 0;
}

/**

bool isSubsequence(char * s, char * t){
    while (*t) {
        if (*s == *t) {
            s++;
        }
        t++;
    }
    if (*s == '\0')
        return 1;
    else
        return 0;
}

*/
