char* toGoatLatin(char* S) {
    char *pc=malloc(sizeof(char)*10000);           // 用來儲存Goat Latin的字串
    int i=0,count=1,j=0;                           // i記步數,count記字數
    char temp;                                     // 用來替換
    while (*S){
        if (*S==' '){                              // 遇到空格
            *(pc+i)=' ';                           // 字串放入空格
            i++;                                   // 步數加1
            S++;                                   // memory移動
        }else{
            if (*S=='a'||*S=='e'||*S=='i'||*S=='o'||*S=='u'||*S=='A'||*S=='E'||*S=='I'||*S=='E'||*S=='U'||*S=='O'){
                while (*S!=' '&&*S!='\0'){         // 遇到母音開頭
                    *(pc+i)=*S;
                    i++;
                    S++;
                }
                *(pc+i)='m';                       // 後面接ma
                i++;
                *(pc+i)='a';
                i++;
                for (j=1;j<=count;j++){            // 依出現字數做增加
                    *(pc+i)='a';
                    i++;
                }
                count++;
            }else{                                 // 遇到子音開頭
                temp=*S;
                S++;
                while (*S!=' '&&*S!='\0'){
                    *(pc+i)=*S;
                    i++;
                    S++;
                }
                *(pc+i)=temp;                      // 第一個子音一道尾部
                i++;
                *(pc+i)='m';
                i++;
                *(pc+i)='a';
                i++;
                for (j=1;j<=count;j++){
                    *(pc+i)='a';
                    i++;
                }
                count++;
            }
        }
    }
    *(pc+i)='\0';                                  // C string over
    return pc;
}

/** Java
class Solution {
    public String toGoatLatin(String S) {
        StringBuilder additional = new StringBuilder();
        additional.append('a');
        StringBuilder result = new StringBuilder();
        for(int i = 0; i < S.length();) {
            while(i < S.length() && S.charAt(i) == ' ') {
                i++;
            }
            if (i == S.length()) break;

            int j = i;
            while(j < S.length() && S.charAt(j) != ' ') {
                j++;
            }

            if (result.length() > 0) {
                result.append(' ');
            }

            if (!isVowel(S.charAt(i))) {
                result.append(S.substring(i + 1, j)).append(S.charAt(i));
            } else {
                result.append(S.substring(i, j));
            }
            result.append("ma").append(additional);

            additional.append('a');
            i = j;
        }

        return result.toString();
    }

    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
}
/** Python
class Solution(object):

    def toGoatLatin(self, S):
        vowel = set('aeiouAEIOU')
        def latin(w, i):
            if w[0] not in vowel:
                w = w[1:] + w[0]
            return w + 'ma' + 'a' * (i + 1)
        return ' '.join(latin(w, i) for i, w in enumerate(S.split()))
*/
