bool isPowerOfFour(int num) {
    double number=(double)num;                   // 锣Θ疊翴计,箇ň俱计菠翴计
    if (!number) return 0;                       // 0 ぃ琌 4 Ωよ计
    else if (number==1) return 1;                // 1 琌 4  0 Ωよ
    while (number>10){
        number/=4;                               // –Ω埃4
        if (number>(int)number)                  // 狦Τ计翴碞安
            return 0;
    }
    if (number==4||number==0)                    // 才 4 Ωよ计兵ン
        return 1;
    else
        return 0;
}
/**
bool isPowerOfFour(int num)     // better
{
    int powerval;
    for(int i=0;i<32;i++)
    {
        powerval=pow(4,i);
        if(powerval==num)
            return true;
        else if(powerval>num)
            return false;
    }
    return false;
}
*/
