bool lemonadeChange(int* bills, int billsSize) {
    int money[2]={0};                   // money[0]:5  money[1]:10
    int i,j;
    for (i=0;i<billsSize;i++){
        if (*(bills+i)==5){             // �յ�5Ԫ������
            money[0]++;
            //continue;
        }else if (*(bills+i)==10){      // �յ�10Ԫ��5Ԫ
            if (money[0]){
                money[0]--;
                money[1]++;
            }else{
                return 0;
            }
        }else if (*(bills+i)==20){      // �յ�20Ԫ��10Ԫ��5Ԫ
            if (money[0]&&money[1]){
                money[0]--;
                money[1]--;
            }else if (money[0]>3){      // ������3��5Ԫ
                money[0]-=3;
            }else{
                return 0;
            }
        }
    }
    return 1;
}
