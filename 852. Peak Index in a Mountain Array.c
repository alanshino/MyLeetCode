int peakIndexInMountainArray(int* A, int ASize) {
    int i=0;
    for (i=0+1;i<ASize-1;i++){                   // 找到一個數大於兩側的數值
        if (*(A+i)>*(A+i-1)&&*(A+i)>*(A+i+1)){
            return i;
        }
    }
    return 0;
}
