bool isLongPressedName(char* name, char* typed) {
    int a[26]={0},slap=0,temp=0;
    int b[26]={0};
    if (*name!=*typed) return 0;            // �p�G�Ĥ@�ӴN���P,����return 0
    while (*typed){
        if (*typed!=*name) return 0;        // �r���P����return 0
        while (*typed==*name){
            a[*typed-97]++;                 // �⥴�F�X�Ӧr
            typed++;
        }
        slap=*(typed-1);                    // �]������,�ҥH�n�Τ@��var�ӫO�s�W�@������m����
        temp=*name;                         // �����t�@�Ӧr����
        while (temp==*name){
            b[temp-97]++;                   // �⥴�F�X��
            name++;
        }
        if (b[temp-97]>a[slap-97]){         // �h���������̩w�n���Ӫ��r�Ʀh
            return 0;
        }else{
            b[temp-97]=0;                   // �k0
            a[slap-97]=0;
        }
    }
    if (*name=='\0'&&*typed=='\0') return 1; // �p�G���@�����S����,����return 0
    else return 0;
}

/**
bool isLongPressedName(char* name, char* typed) {
    int typeLen = strlen(typed);
    int nameLen = strlen(name);
    int i, j = 0;
    for(i = 0; i < typeLen; i++){
        if(name[j] == typed[i] && j < nameLen){
            j++;
        }
        else if(typed[i] == typed[i-1]){
            continue;
        }
        else
            return false;
    }
    if(j != nameLen)
        return false;
    return true;
}
*/
