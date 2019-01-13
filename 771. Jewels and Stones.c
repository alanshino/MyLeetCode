int numJewelsInStones(char* J, char* S) {
    int  jewel=0;
    char *pj=J;
    while (*S){
        while (*pj){
            if (*S==*pj){
                jewel++;
                break;
            }else{
                pj++;
            }
        }
        pj=J;
        S++;
    }
    return jewel;
}
