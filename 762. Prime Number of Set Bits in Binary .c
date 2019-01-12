int prime(int n);
int countPrimeSetBits(int L, int R) {    // very slow
    int i=0,j=0,count=0,total=0;
    for (i=L;i<=R;i++){
        j=i;
        while (j){
            if (j%2){
                count++;    
            }else{
                j>>=1;
                continue;
            }
            j>>=1;
        }
        if ((count!=1)&&prime(count)){
            total++;   
        }
        count=0;
    }
    return total;
}

int prime(int n){
    int i=0;
    if (n==2||n==3) return 1;
    for (i=2;i<n;i++){
        if (n%i){
            continue;   
        }else{
            return 0;   
        }
    }
    return 1;
}
