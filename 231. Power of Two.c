bool isPowerOfTwo(int n) {
    long int c=1;
    while (c<=n){                 // �P�_�۵�
        if (c==n){
            return 1;
        }
        c*=2;                     // �C��*2
    }
    return 0;
}
