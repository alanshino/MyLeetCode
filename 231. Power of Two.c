bool isPowerOfTwo(int n) {
    long int c=1;
    while (c<=n){                 // 如果沒有小於
        if (c==n){                // 先判斷避免為1的情況
            return 1;
        }
        c*=2;                     // 每次乘2
    }
    return 0;
}
