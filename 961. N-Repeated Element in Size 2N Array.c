int repeatedNTimes(int* A, int ASize) {
    char *pa=calloc(10000,sizeof(char)); // faster
    for (int i=0;i<ASize;i++){
        if (*(pa+*(A+i))){
            return *(A+i);    
        }else{
            (*(pa+*(A+i)))++;
        }
    }
    return 0;
}

int repeatedNTimes(int* A, int ASize) {
    int *pa=calloc(10000,sizeof(int));
    for (int i=0;i<ASize;i++){
        if (*(pa+*(A+i))){
            return *(A+i);
        }else{
            (*(pa+*(A+i)))++;
        }
    }
    return 0;
}
