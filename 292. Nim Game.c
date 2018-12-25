bool canWinNim(int n) {
    if (n<=3){
        return 1;
    }else if (n%4==0){
        return 0;
    }else{
        return 1;
    }
}
