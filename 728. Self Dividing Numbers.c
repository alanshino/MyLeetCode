/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int i,n=0,*preturn=NULL;
    for (i=left;i<=right;i++){  // 眖left numberright number
        if (digitalright(i)){
            n++;                // 絋﹚Τ碭才兵ン
        }
    }
    *returnSize=n;
    preturn=malloc(sizeof(int)* *returnSize); // だ皌
    n=0;
    for (i=left,n=0;i<=right;i++){
        if (digitalright(i)){   // 盢才兵ン秈array
            *(preturn+n)=i;
            n++;
        }
    }
    return preturn ;
}

int digitalright(int i){
    int digital=0;
    int n=i;
    while (i){
        digital=i%10;          // 程
        if (digital==0){       // 肈ヘ璶―ぃ眔Τ0
            return 0;
        }else if (n%digital==0){  // 程计俱埃计
            i=i/10;               // 计搭程计
        }else{
            return 0;
        }
    }
    return 1;
}
