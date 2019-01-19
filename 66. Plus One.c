/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *preturn=NULL;
    int slap=0,i=0,count=0;
    if (*(digits+digitsSize-1)<9){                  // 如果不需要進位,直接加1後return
        (*(digits+digitsSize-1))++;
        *returnSize=digitsSize;
        return digits;
    }
    for (i=0;i<digitsSize;i++){                     // 判斷是否全部都為9,代表全進位
        if (*(digits+i)==9){
            slap++;
        }else{
            break;
        }
    }
    if (slap==digitsSize){                           // 如果全進位
        preturn=malloc(sizeof(int)*(digitsSize+1));  // malloc一個比原array大一個位置的空間
        *returnSize=digitsSize+1;
        for (i=0;i<digitsSize+1;i++){                // 只有開頭為1,其他都是0
            if (i==0){
                *(preturn+i)=1;
            }else{
                *(preturn+i)=0;
            }
        }
        return preturn;
    }else{
        *returnSize=digitsSize;                     // 如果有需要進位,但不是全進位
        for (i=digitsSize-1;i>=0;i--){              // 改成從最後位開始
            if (*(digits+i)==9){
                count=1;                            // 用一個count來紀錄是否有進位
                *(digits+i)=0;                      // 原位先設為0
            }else if (count){                       // 不須進位,但前面有進位
                count=0;
                (*(digits+i))++;                    // 本位加1
                return digits;                      // 直接return
            }
        }
    }
    return digits;
}
