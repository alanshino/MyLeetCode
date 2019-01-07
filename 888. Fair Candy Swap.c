/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int i,j,atotal=0,btotal=0,change=0,*preturn;
    *returnSize=2;
    preturn=malloc(sizeof(int)**returnSize);
    for (i=0;i<ASize;i++){                          // ��XA���`�M
        atotal+=*(A+i);
    }
    for (i=0;i<BSize;i++){                          // ��XB���`�M
        btotal+=*(B+i);
    }
    change=(atotal-btotal)/2;                       // �洫�𶷺����`�M�۴�/2
    for (i=0;i<BSize;i++){
        for (j=0;j<ASize;j++){
            if (*(B+i)+change==*(A+j)){             // �q���array����X�洫��
                *(preturn+0)=*(A+j);
                *(preturn+1)=*(B+i);
                return preturn;
            }
        }
    }
    return (int *)0;                                // return type is a pointer to integer
}
