int prime(int n);
int numPrimeArrangements(int n){
    const int modulo = 1000000007;   // return the answer modulo 10^9 + 7
    int prime_number = 0;
    long long int return_value1 = 1, return_value2 = 1;
    for (int i = 1; i <= n; i++) {
        if (prime(i)) {
            prime_number++;          // т借计羆计
        }
    }
    for (int i = 1; i <= prime_number; i++) {
        return_value1 = i * return_value1 % modulo;
    }
    for (int i = 1; i <= n - prime_number; i++) {
        return_value2 = i * return_value2 % modulo;
    }
    return return_value1 * return_value2 % modulo;  // ㄏノΑ (P! * (n - P)!)  P 借计羆计
}

int prime(int n)
{
    if (n <= 1)
        return 0;
    else if (n == 2 || n == 3)
        return 1;
    for (int i = 2; i <= n - 1; i++) {
        if (!(n % i)) {
            return 0;
        }
    }
    return 1;
}
