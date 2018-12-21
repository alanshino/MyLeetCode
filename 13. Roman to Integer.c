int toint(char c){
    int ans=0;
    switch (c){
            case 'I':
                ans=1;
                break;
            case 'V':
                ans=5;
                break;
            case 'X':
                ans=10;
                break;
            case 'L':
                ans=50;
                break;
            case 'C':
                ans=100;
                break;
            case 'D':
                ans=500;
                break;
            case 'M':
                ans=1000;
                break;
        }
    return ans;
}


int romanToInt(char* s) {
    int sum=0;
    while (*s!='\0'){
        if ((toint(*s)<toint(*(s+1))) && (*(s+1)!='\0')){
            sum+=toint(*(s+1))-toint(*s);
            s+=2;
        }else if ((toint(*s)>=toint(*(s+1))) && (*(s+1)!='\0')){
            sum+=toint(*s);
            s++;
        }else{
            sum+=toint(*s);
            s++;
        }
        //s+=2;
    }
    return sum;
}
