int rotatedDigits(int N) {
    int total=0,i=0;
    for (i=1;i<=N;i++){
        if (Rotated(i)){                             // call function
            total++;
        }
    }
    return total;                                    // ���`�@���X��
}

int Rotated(int n){
    int yes=0;
    while (n){
        if (n%10==3||n%10==4||n%10==7){              // ������� 3  4  7 ����@��
            return 0;
        }
        if (n%10==2||n%10==5||n%10==6||n%10==9){     // �@�w�n�� 2  5  6  9 �䤤�@��
            yes=1;
        }
        n/=10;                                       // ��n��10�H����
    }
    if (yes) return 1;
    else return 0;
}
