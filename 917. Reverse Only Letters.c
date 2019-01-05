char* reverseOnlyLetters(char* S) {
    int i=strlen(S),j=0;
    int head=0,tail=i-1;
    char temp;
    while (head!=tail&&head<tail){
        if ((*(S+head)>=65&&*(S+head)<=90)||(*(S+head)>=97&&*(S+head)<=122)){
            if ((*(S+tail)>=65&&*(S+tail)<=90)||(*(S+tail)>=97&&*(S+tail)<=122)){
                temp=*(S+head);
                *(S+head)=*(S+tail);
                *(S+tail)=temp;
            }else{
                tail--;
                continue;
            }
        }else{
            head++;
            continue;
        }
        head++;
        tail--;
    }
    return S;
}

