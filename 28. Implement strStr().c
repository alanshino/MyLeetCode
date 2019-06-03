/**
    alphabet_number function 用來計算總共的字數
    依序循序走訪字串
    遇到相同的開始判斷並走訪
    當 needle 走完代表找到相同的部分並回傳起始住標
    如果中斷 haystack 退回原位後 +1                 // 代表從下一個位置開始
    index 用來判斷 needle 起始位置
    沒找到相同的回傳 -1
*/

int strStr(char * haystack, char * needle){
    char *pc = needle;
    int index = 0, i = 0;
    int input1 = alphabet_number(haystack), input2 = alphabet_number(needle);
    if (!*needle && !*haystack)
        return 0;
    if (input1 < input2)
        return -1;
    else if (input1 && !input2)
        return 0;
    /*
    while (*haystack) {
        if (*pc == *haystack) {
            index = i;
            pc = needle + 1;
            haystack++;
            while (*pc) {
                if (*pc == *haystack) {
                    pc++;
                    haystack++;
                }else {
                    index = -1;
                    break;
                }
            }
            if (index > 0)
                return index;
        }
        haystack++;
        i++;
    }
    */
    while (*haystack) {
        if (*haystack == *pc) {
            while ((*haystack == *pc) && *haystack != NULL && *pc != NULL) {
                i++;
                haystack++;
                pc++;
            }
            if (*pc == NULL) {
                return index;
            }else {
                pc = needle;
                haystack = haystack - i + 1;
                i = 0;
                index++;
            }
        }else {
            haystack++;
            index++;
        }
    }
    return -1;
}

int alphabet_number(char *pc)
{
    int i = 0;
    while (*pc) {
        i++;
        pc++;
    }
    return i;
}

/** C faster

int strStr(char * haystack, char * needle){

    int len_haystack = strlen(haystack);
    int len_needle = strlen(needle);
    int i = 0, j= 0;
    int temp = 0;

    for(i=0; i<=(len_haystack-len_needle); i++)
    {
        temp = i;
        for(j=0;j<len_needle;j++)
        {
            if(haystack[temp] == needle[j]){}
            else break;
            temp++;
        }
        if(j == len_needle) return i;
    }

    return -1;

}

*/

/** C

int strStr(char* haystack, char* needle) {
    if(needle == NULL || *needle == '\0') return 0;

    int i, imax;
    int lhaystack = strlen(haystack);
    int lneedle = strlen(needle);

    imax = lhaystack - lneedle + 1;
    for(i = 0; i < imax; i++) {
        if(!strncmp(haystack + i, needle, lneedle)) return i;
    }
    return -1;
}

/** C

void GetNext(char* P, int len, int* next)
{
    if(NULL == P)
        return;

    next[0] = -1;
    int k=-1;
    int j=0;
    while(j < len-1)
    {
        if(-1 == k || P[k] == P[j])
        {
            ++k;
            ++j;
            next[j] = k;
        }
        else
            k = next[k];
    }
}


int strStr(char * haystack, char * needle){

    if(NULL == haystack)
        return -1;
    if(NULL == needle)
        return 0;

    int Plen = strlen(needle);
    if(0 == Plen)
        return 0;

    int *next = NULL;
    next  = (int*)calloc(Plen,sizeof(int));
    if(NULL == next)
        return -1;

    int i = 0;
    int j = 0;
    int Tlen = strlen(haystack);
    GetNext(needle, Plen, next);
    while (haystack[i] != '\0' && j < Plen)
	{
		if (j == -1 || haystack[i] == needle[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}

    if(next)
        free(next);

	if (j == Plen)
		return i - j;
	else
		return -1;

}

*/

/** Java

class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.isEmpty()){
            return 0;
        }

        if(needle.length() > haystack.length()) {
            return -1;
        }

        if(needle.equals(haystack)) {
            return 0;
        }

        int nLen = needle.length();
        int boundary = haystack.length()-nLen;
        for(int i=0; i<=boundary; i++) {
            String sub = haystack.substring(i, nLen+i);
            if(sub.equals(needle)) {
                return i;
            }
        }

        return -1;
    }
}

public class Solution {
    public int strStr(String haystack, String needle) {
        return haystack.indexOf(needle);
    }
}

*/

/** C++

class Solution {
public:
    int strStr(string haystack, string needle) {
        // check if str is empty
        // search haystack
        // return anwer
        // -
        if (needle.length() == 0){return 0;}
        auto index = haystack.find(needle, 0);
        if (index != string::npos){
            return index;
        }
        else {return -1;}
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {

        if(haystack.length()<needle.length())
            return -1;
        else
            return haystack.find(needle);

        }

};

*/
