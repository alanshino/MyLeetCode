bool hasAlternatingBits(int n) {
    int i=n%2;
    while (n){
        if ((n>>1)%2!=i){
            i=(n>>1)%2;
            n>>=1;
        }else{
            return 0;
        }
    }
    return 1;
}
