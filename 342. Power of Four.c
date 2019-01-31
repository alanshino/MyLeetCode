bool isPowerOfFour(int num) {
    double number=(double)num;                   // ���ন�B�I��,�w������Ƭٲ����I��
    if (!number) return 0;                       // 0 ���O 4 �������
    else if (number==1) return 1;                // 1 �O 4 �� 0 ����
    while (number>10){
        number/=4;                               // �C����4
        if (number>(int)number)                  // �p�G���p���I�N����
            return 0;
    }
    if (number==4||number==0)                    // �ŦX 4 ������Ʊ���
        return 1;
    else
        return 0;
}
/**
bool isPowerOfFour(int num)     // better
{
    int powerval;
    for(int i=0;i<32;i++)
    {
        powerval=pow(4,i);
        if(powerval==num)
            return true;
        else if(powerval>num)
            return false;
    }
    return false;
}
*/
