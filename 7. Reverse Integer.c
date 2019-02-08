int reverse(int x) {
    int a=1,b=0,d[32]={0};
    long int c=0;
    if (x>2147483647)          // 避免 x 產生 integer overflow
        return 0;
    else if (x<-2147483647)
        return 0;
    if (x<0){
        a=-1;
        x*=a;
    }
    while (x){
        d[b]=x%10;             // 紀錄最後一位的值
        b++;
        x/=10;
    }
    for (x=0;x<b;x++){         // reverse integer 因為 array 第一位是 x 最後位
        c=c*10+d[x];
    }
    c*=a;
    if (c>2147483647)          // // 避免 return value 產生 integer overflow
        return 0;
    else if (c<-2147483647)
        return 0;
    return c;
}

/** C faster
int reverse(int x) {
    int ans=0;
    while(x!=0)
    {
        int pop=x%10;
        x=x/10;
        if(ans>INT_MAX/10 || (ans==INT_MAX/10 && pop>7))
            return 0;
        if (ans < INT_MIN/10 || (ans == INT_MIN / 10 && pop < -8))
            return 0;
        ans=10*ans+pop;
    }
    return ans;
}
*/
