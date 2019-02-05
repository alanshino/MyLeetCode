int hammingWeight(uint32_t n) {
    int i=0;
    while (n){
        if (n%2)        // 遇到位元為 1
            i++;
        n>>=1;          // 每次位元往右遞移一個
    }
    return i;
}

/** C  faster
uint32_t log2n(uint32_t a){
    return (a > 1) ? 1 + log2n(a / 2) : 0;
}

int hammingWeight(uint32_t n) {
    int result = 0;
    for (uint32_t i = pow(2,log2n(n)); i != 0; i /= 2) {
        if (n / i == 1)
            result++;
        n = n % i;
    }
    return result;
}
*/

/** C
int hammingWeight(uint32_t n) {
    int sum = 0;
    while (n)
    {
        n &= n-1;
        ++sum;
    }
    return sum;
}
*/
