bool isPerfectSquare(int num) {
    int i=0;
    for (i=0;i<=num/4+1;i++){
        if (i*i==num){
            return i;   
        }
    }
    return 0;
}
