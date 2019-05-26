/** Go  */

func removeOuterParentheses(S string) string {
    var res bytes.Buffer
    counter := 0
    for _,c := range S {
        if counter != 0 && !(counter == 1 && c == ')') {
            res.WriteRune(c)
        }
        if c == '(' {
            counter++
        } else {
            counter--
        }
    }
    return res.String()
}

func removeOuterParentheses(S string) string {
    if len(S) == 0 {
        return ""
    }
    var parenlevel int
    var primdecomp []rune
    for _, r := range S {
        if r == '(' {
            parenlevel += 1
        }
        if parenlevel > 1 {
            primdecomp = append(primdecomp, r)
        }
        if r == ')' {
            parenlevel -= 1
        }
    }
    return string(primdecomp)
}

/** C  */

char* removeOuterParentheses(char* S) {
    int left_count=0,right_count=0,start=0,j=0,count=0;
    char *pc=malloc(sizeof(char)*10000);                         // 依題目設定最大值
    int i=0;
    if (!*S)
        return 0;
    for (i=0;*(S+i)!='\0';i++) {
        if (*(S+i)=='(')
            left_count++;
        else
            right_count++;
        if (!(right_count-left_count)) {                        // 每當完成 ()
            left_count=0;
            right_count=0;
            for (j=start+1;j<i;j++) {
                *(pc+count++)=*(S+j);
            }
            start=i+1;
        }
    }
    *(pc+count++)='\0';
    return pc;
}

char* removeOuterParentheses(char * S){
    int l=strlen(S);
    char* ret=(char*)malloc(sizeof(char)*l);
    char* nowS=S,*nowSStart=S,*nowRet=ret;
    int flag=0;
    while(*nowS!='\0'){
        if(*nowS=='('){
            ++flag;
        }
        else{
            --flag;
        }
        if(flag==0){
            int step=nowS-nowSStart-1;
            memcpy(nowRet,nowSStart+1,sizeof(char)*step);
            nowSStart=nowS+1;
            nowRet=nowRet+step;
        }
        ++nowS;
    }
    *nowRet='\0';
    return ret;
}

/** C++  */

class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<int> st;
        string ans;
        int len=S.size();
        vector<bool> v(len,false);
        for(int i=0;i<len;i++){
          if(S[i]=='(') st.push(i);
          else if(S[i]==')'){
            int tmp=st.top();
            st.pop();
            if(st.empty()){
              v[tmp]=true;
              v[i]=true;
            }
          }
        }
        for(int i=0;i<len;i++){
          if(v[i]==false) ans.push_back(S[i]);
        }
      return ans;
    }
};

class Solution {
public:
    string removeOuterParentheses(string S) {
        int left = 0;
        string res = "";
        for (char ch : S) {
            if (ch == '(') ++left;
            if (left > 1) res += ch;
            if (ch == ')') left--;
        }
        return res;
    }
};

static const auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    string removeOuterParentheses(string S) {
        string ret= "";
        int cnt = 0;
        for(int i=0; i<S.size(); i++){
            if(S[i] == '('){
                cnt--;
                if(cnt==-1)
                    continue;
            }
            if(S[i] == ')'){
                cnt++;
                if (cnt == 0)
                    continue;
            }
            ret += S[i];
        }
        return ret;
    }
};

/** Python  */

from collections import deque
class Solution(object):
    def removeOuterParentheses(self, S):
        """
        :type S: str
        :rtype: str
        """
        left = 0
        res = []
        for i, ch in enumerate(S):
            if ch == "(":
                if left > 0:
                    res.append(ch)
                left += 1
            else:
                left -= 1
                if left > 0:
                    res.append(ch)
        return "".join(res)

class Solution(object):
    def removeOuterParentheses(self, S):

        left = 0
        right = 0
        last = 1
        slen = len(S)
        r = ""

        for i in range(slen):
            if S[i] == '(':
                left += 1
            else:
                right += 1
                if left == right:
                    r = r + (S[last:i])
                    last = i + 2

        return r

/** Java  */

class Solution {
    public String removeOuterParentheses(String S) {
        int length = S.length();
        if (length <= 2 ) {
            return "";
        }

        // StringBuilder result = new StringBuilder();
        char[] result = new char[length];
        int resultLength = 0;
        int count = 0;
        char[] chars = S.toCharArray();
        char ch;

        for (int i = 0; i < length; i ++) {
            ch = chars[i];
            if (ch == '(') {
                count ++;
            }

            if (count > 1) {
                // result.append(ch);
                result[resultLength++] = ch;
            }

            if (ch == ')') {
                count --;
            }
        }

        // return result.toString();
        return new String(result, 0, resultLength);
    }
}

class Solution {
    public String removeOuterParentheses(String S) {
if (S != null) {
            int oc = 0; // openparanthesisCount
            int cc = 0; //closeparanthesisCount
            boolean foc = true; // firstOpeningParenthesis
            StringBuilder sb = new StringBuilder();

            char[] c = S.toCharArray();
            for(int i=0 ; i< c.length ; i++){
                if(c[i] == '(' ){
                    if(foc)
                        foc = false;
                    else {
                        sb.append(c[i]);
                        oc++;
                    }
                }
                else if(c[i] == ')'){
                    if(cc == oc){ // i.e closing outer parenthesis
                        oc = 0;
                        cc = 0;
                        foc = true;
                    }
                    else{
                        sb.append(c[i]);
                        cc++;
                    }
                }
            }
            return sb.toString();
        }
        return null;
    }

}


