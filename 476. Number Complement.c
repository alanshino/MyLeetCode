int findComplement(int num) {
    int n=0;
    int i=0,number=0;
    int *pa=malloc(sizeof(int)*31);
    while (num>0){
        if (num&1==1){ //判斷最右邊位元是否為1
            n++;
            num>>=1;
        }else{
            *(pa+i)=n; //如果判斷結果為0就記錄那個位元的位置 從0開始
            i++;
            n++;
            num>>=1; //每次往右消一個位元
        }
    }
    for (n=0;n<i;n++){
        number+=pow(2,*(pa+n)); //將紀錄的位元用2次方拼湊出來
    }
    return number;
}
