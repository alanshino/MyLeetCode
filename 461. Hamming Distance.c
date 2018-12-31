int hammingDistance(int x, int y) {
    int i = x ^ y;                 // x y XOR
    int n = 0;
    while (i > 0){
        if ((i & 1) == 1) n++;     // i 1 AND
        i >>= 1;                   // i -> 1 digital
    }
    return n;
}
