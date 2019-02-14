int isPrime(int n){
    int i;
    if (n <= 1)
        return 0;

    for(i=2; i*i<=n; i++)
        if(!(n%i))
            return 0;
    return 1;
}

int countPrimes(int n) {
    int i, count = 0;

    for (i=1; i<n; i++)
        if (isPrime(i))
            count++;

    return count;
}

/** C faster
int countPrimes(int n) {
    bool *not_prime;
    int count = 0;
    long i, j;
    not_prime = malloc(sizeof(bool) * (n + 1));
    memset(not_prime, 0, sizeof(bool) * (n + 1));

    for (i = 2; i < n; i++) {
        if (not_prime[i])
            continue;
        not_prime[i] = true;
        count++;
        for (j = i * i; j <= n; j += i) {
           not_prime[j] = true;
        }
    }
    return (count);
}
*/
