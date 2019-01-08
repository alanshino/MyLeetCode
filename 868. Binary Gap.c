int binaryGap(int N) {
    int gap=0,flip_flop=0;                  // 判斷步數 , 判斷是否為1
    int max=0;                              // 取最大值
    if (N<=1){
        return 0;
    }else{
        while (N){
            if (N%2&&flip_flop==0){         // 現在位元為1 , 且之前未出現1
                flip_flop=1;
            }else if (N%2&&flip_flop!=0){   // 現在位元為1 , 且前面已出現1
                gap++;
                if (gap>max) max=gap;       // 紀錄最大值
                gap=0;
            }else{
                if (flip_flop==1){
                    gap++;
                }
            }
            N>>=1;                         // loop減少位元
        }
    }
    return max;
}
