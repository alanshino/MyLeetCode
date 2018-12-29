bool hasAlternatingBits(int n) {
    int i=n%2; //取得最右位元的數值
    while (n){
        if ((n>>1)%2!=i){ // 往右遞移的位元與最右位元的判斷
            i=(n>>1)%2;  //如果不同就取得往遞移位元的數值
            n>>=1; //往右遞移
        }else{
            return 0;
        }
    }
    return 1;
}
