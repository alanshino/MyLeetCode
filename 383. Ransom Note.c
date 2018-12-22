bool canConstruct(char* ransomNote, char* magazine) {
    int n=strlen(ransomNote);
    int k=strlen(magazine);
    int number=0;
    int a[26]={0};
    int b[26]={0};
    int i=0;
    if (n>k){
        return 0;
    }else{
        while (*ransomNote!='\0'){
            number=*ransomNote-97; // *ransomNote%97
            a[number]++;
            ransomNote++;
        }
        while (*magazine!='\0'){
            number=*magazine-97;// *magazine%97
            b[number]++;
            magazine++;
        }
        for (i=0;i<26;i++){
            if (a[i]>b[i]){
                return 0;   
            }
        }
        return 1;
    }
}

