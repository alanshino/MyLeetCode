/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** reorderLogFiles(char** logs, int logsSize, int* returnSize) {
    int i=0;
    int strlong=0,number=0,call[logsSize],j=0,k=0,copy=0;
    char **pc=NULL;
    char *ps=NULL;
    *returnSize=logsSize;
    pc=malloc(sizeof(char *)*logsSize);
    for (i=0;i<logsSize;i++){
        ps=*(logs+i);
        while (*ps!='\0'){
            if (*ps!=' '&&*ps>=97&&*ps<=122){
                strlong++;
            }
            if (*ps>='0'&&*ps<='9'){
                number++;
            }
            ps++;
        }
        //printf("%d %d\n",strlong,number);
        if (strlong>number){
            *(pc+j)=*(logs+i);
            //printf("%s\n",*(pc+j));
            j++;
        }else{
            call[k]=i;
            k++;
        }
        strlong=0;
        number=0;
    }
    for (i=0;i<k;i++){
        *(pc+j+i)=*(logs+call[i]);
    }
    return pc;                         // return pointer to pointer to char
}/** facefucking */
