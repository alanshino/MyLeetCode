int maxProfit(int* prices, int pricesSize) {
    int i,j;
    int max=0;
    for (i=0;i<pricesSize-1;i++){
        for (j=i+1;j<pricesSize;j++){
            if ((*(prices+j)-*(prices+i))>max){
                max=*(prices+j)-*(prices+i);
            }
        }
    }
    return max;
}
