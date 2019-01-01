bool lemonadeChange(int* bills, int billsSize) {
    int money[2]={0};                   // money[0]:5  money[1]:10
    int i,j;
    for (i=0;i<billsSize;i++){
        if (*(bills+i)==5){             // 收到5元不用找
            money[0]++;
            //continue;
        }else if (*(bills+i)==10){      // 收到10元找5元
            if (money[0]){
                money[0]--;
                money[1]++;
            }else{
                return 0;
            }
        }else if (*(bills+i)==20){      // 收到20元找10元根5元
            if (money[0]&&money[1]){
                money[0]--;
                money[1]--;
            }else if (money[0]>3){      // 或是找3張5元
                money[0]-=3;
            }else{
                return 0;
            }
        }
    }
    return 1;
}
