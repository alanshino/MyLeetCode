int addDigits(int num) {
    int n=0;
    if (num<10) return num;
    while (num>=10){
        n=addD(num);
        num=n;
    }
    return num;
}

int addD(int n){
    int sum=0;
    while (n/10!=0){
        sum+=n%10;
        n/=10;
    }
    sum+=n;
    return sum;
}
