int firstUniqChar(char* s) {
    int a[26]={0};
    char *ps=s;                  //pointer to char to remember location
    int i=0;
    while (*s){
        a[*s-97]++;              //�̷�ascii�X�W�[array����
        s++;                     //pointer++ add char size
    }
    while (*ps){
        if (a[*ps-97]==1){       //���Ĥ@�ӳ�ƭ�,�q��l�r��}�l��
            return i;            //return location
        }
        ps++;                    //pointer++
        i++;                     //location++
    }
    return -1;                   //�S���^��-1
}
