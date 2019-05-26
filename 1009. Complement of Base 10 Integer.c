int bitwiseComplement(int N) {
    int c = 1;
    while (c < N) {
        c = (c << 1) | 1;
        printf("%d\n",c);
    }
    return N ^ c;
}

int bitwiseComplement(int N) {
    int m = 1;
    while (m < N) {
        m = m << 1 | 1;
    }
    return N ^ m;
}

/** C++

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N==0) return 1;
        int n = helper(N);
        cout<<n;
        return (~N) & n;
    }
    int helper(int N) {
        int n = 0;
        while (N) {
            n++;
            N >>= 1;
        }
        return pow(2, n) - 1;
    }
};
