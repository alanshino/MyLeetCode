/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* S, char C, int* returnSize) {
    int *pa=NULL;
    int i=0,j=0,benchmark=0,slap=0,start=0;
    *returnSize=strlen(S);
    pa=malloc(sizeof(int)**returnSize);                // 建立return array
    for (i=0;i<*returnSize;i++){
        *(pa+i)=0;
    }
    for (i=0;i<*returnSize;i++){                       // 從頭開始找
        if (*(S+i)==C){
            continue;
        }else{
            for (j=i;j<*returnSize;j++){               // 找到與指定字元的相對距離,從0開始
                if (*(S+j)==C){
                    *(pa+i)=j-i;
                    break;
                }
            }
        }
    }
    for (i=*returnSize-1;i>=0;i--){
        if (*(S+i)==C){
            continue;
        }else{
            for (j=i;j>=0;j--){
                if (*(S+j)==C){
                    if (i-j<*(pa+i)||*(pa+i)==0){     // 找到與指定字元的相對距離,從最後開始
                        *(pa+i)=i-j;
                        break;
                    }
                }
            }
        }
    }
    return pa;
}
