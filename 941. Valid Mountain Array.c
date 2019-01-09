bool validMountainArray(int* A, int ASize) {
    int i=0,block=0;
    if (ASize<3){
        return 0;
    }else{
        for (i=0;i<ASize-1;i++){
            if (*(A+i)<*(A+i+1)){
                continue;
            }else{
                block=i;
                break;
            }
        }
        if (i==ASize-1||i==0) return 0;
        for (i=block;i<ASize-1;i++){
            if (*(A+i)>*(A+i+1)){
                continue;
            }else{
                return 0;
            }
        }
        return 1;
    }
}