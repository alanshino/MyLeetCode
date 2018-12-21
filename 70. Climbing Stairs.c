int climbStairs(int n) {
    int a[1000]={0};
    int i=0;
    a[0]=1;
    a[1]=1;
    a[2]=2;
    for (i=3;i<1000;i++){
        a[i]=a[i-1]+a[i-2];
    }
    return a[n];
}
