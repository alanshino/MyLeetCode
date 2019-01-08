int smallestRangeI(int* A, int ASize, int K) {
    int dis=test(A);
    int sub=2*K;
    if (dis-sub<=0){
        return 0;
    }else{
        return dis-sub;
    }
}

int test(int *pa,int Size){
    int max=0,min=10000,i=0;
    for (i=0;i<Size;i++){
        if (*(pa+i)>max){
            max=*(pa+i);
        }
        if (*(pa+i)<min){
            min=*(pa+i);
        }
    }
    return max-min;
}
