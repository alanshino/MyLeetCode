bool hasAlternatingBits(int n) {
    int i=n%2; //���o�̥k�줸���ƭ�
    while (n){
        if ((n>>1)%2!=i){ // ���k�������줸�P�̥k�줸���P�_
            i=(n>>1)%2;  //�p�G���P�N���o�������줸���ƭ�
            n>>=1; //���k����
        }else{
            return 0;
        }
    }
    return 1;
}
