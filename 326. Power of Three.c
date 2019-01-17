bool isPowerOfThree(int n) {
    double a=n;
    if (n==3||n==9||n==1) return 1;
    while (a>10){
        a/=3;                  // /3�P�_�O�_�ۦP
        if ((a-(int)a)>0){     // �i�ಣ�ͤp���I,cast��j��0�̬���
            return 0;
        }
    }
    if (a==3||a==9) return 1;
    else return 0;
}

bool isPowerOfThree(int n) {   // the faster
    long int c=1;
    while (c<=n){
        if (c==n){
            return 1;
        }
        c*=3;                 // *3�P�_�O�_�ۦP
    }
    return 0;
}
