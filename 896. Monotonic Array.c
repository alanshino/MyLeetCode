bool isMonotonic(int* A, int ASize) {
    int i=0,add=0;
    if (ASize<=1){
        return 1;
    }
    for (i=0;i<ASize-1;i++){
        if (*(A+i)>=*(A+i+1)){
            continue;   
        }else{
            add++;
            break;
        }
    }
    if (add==0) return 1;
    for (i=0;i<ASize-1;i++){
        if (*(A+i)<=*(A+i+1)){
            continue;   
        }else{
            add++;
            break;
        }
    }
    if (add==2){
        return 0;
    }else{
        return 1;
    }
}


