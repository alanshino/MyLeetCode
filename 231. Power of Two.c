bool isPowerOfTwo(int n) {
    long int c=1;
    while (c<=n){                 // §PÂ_¬Ûµ¥
        if (c==n){
            return 1;
        }
        c*=2;                     // ¨C½ü*2
    }
    return 0;
}
