int hammingDistance(int x, int y) {
    int i = x ^ y;
    int n = 0;
    while (i > 0){
        if ((i & 1) == 1) n++;
        i >>= 1;
    }
    return n;
}
