int findComplement(int num) {
    int n=0;
    int i=0,number=0;
    int *pa=malloc(sizeof(int)*31);
    while (num>0){
        if (num&1==1){ //�P�_�̥k��줸�O�_��1
            n++;
            num>>=1;
        }else{
            *(pa+i)=n; //�p�G�P�_���G��0�N�O�����Ӧ줸����m �q0�}�l
            i++;
            n++;
            num>>=1; //�C�����k���@�Ӧ줸
        }
    }
    for (n=0;n<i;n++){
        number+=pow(2,*(pa+n)); //�N�������줸��2�������X��
    }
    return number;
}
