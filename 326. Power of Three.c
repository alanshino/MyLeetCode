bool isPowerOfThree(int n) {
    double a=n;
    if (n==3||n==9||n==1) return 1;
    while (a>10){
        a/=3;                  // /3判斷是否相同
        if ((a-(int)a)>0){     // 可能產生小數點,cast後大於0者為假
            return 0;
        }
    }
    if (a==3||a==9) return 1;
    else return 0;
}

bool isPowerOfThree(int n) {   // the faster
    long int c=1;
    while (c<=n){
        if (c==n){
            return 1;
        }
        c*=3;                 // *3判斷是否相同
    }
    return 0;
}
