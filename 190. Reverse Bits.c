uint32_t atouint32_t(char *pc);
uint32_t reverseBits(uint32_t n) {
    char *pc=malloc(sizeof(char)*33);          // �]���n���ഫ���r��,�� 32 �� bits �[�W�O�d '\0' +1
    int i=0;
    for (i=0;i<32;i++){
        *(pc+i)=n%2+'0';                       // �]���O�G�i��
        n>>=1;                                 // �C�����k���ʤ@�Ӧ줸
    }
    *(pc+32)='\0';
    //printf("%s",pc);
    return atouint32_t(pc);                    // call function
}

uint32_t atouint32_t(char *pc){
    uint32_t n=0;
    //printf("\n%s",pc);
    while (*pc!='\0'){
        n=n*2+*pc-'0';                         // �C���[�W���ʪ��r����,�����W2
        pc++;
    }
    return n;
}

/** C
uint32_t reverseBits(uint32_t n) {
    uint32_t count = 8 * sizeof(n) - 1;
    uint32_t reverse = n;
    n >>= 1;
    while (n) {
        reverse <<= 1;
        reverse |= n & 1;
        n >>= 1;
        count--;
    }
    reverse <<= count;
    return reverse;
}
*/
