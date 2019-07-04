/**
    Given an integer, return its base 7 string representation.
    Input: 100
    Output: "202"
    Input: -7
    Output: "-10"
    10 進位制轉換成 7 進位制
*/
char * convertToBase7(int num){
    int save_num = num;                 // 儲存原始數值 , 為接下來的記憶體分配做配置
    char *preturn = NULL;
    int i = 0;
    if (!num) {                         // 如果 Input 是 0 , 回傳 "0"
        preturn = malloc(sizeof(char) * 2);
        preturn[0] = '0';
        preturn[1] = '\0';
        return preturn;
    }
    if (save_num < 0) {                 // 如果 Input 是負數 , 需要在前面保留 '-' 符號
        save_num = -save_num;
        i++;
        while (save_num) {
            save_num /= 7;
            i++;
        }
        preturn = malloc(sizeof(char) * (i + 1));
        preturn[i] = '\0';
        num = -num;
        for (int j = i - 1; j > 0; j--) {
            preturn[j] = num % 7 + '0';
            // printf("%d ",num % 7);
            num /= 7;
        }
        preturn[0] = '-';
    }else {                                         // 如果是正數則不用預留空間
        while (save_num) {
            save_num /= 7;
            i++;
        }
        preturn = malloc(sizeof(char) * (i + 1));
        preturn[i] = '\0';
        for (int j = i - 1; j >= 0; j--) {
            preturn[j] = num % 7 + '0';
            num /= 7;
        }
    }
    return preturn;
}

/** C++

class Solution {
public:
    string convertToBase7(int num) {
        string result;
        bool bNegative = num >= 0 ? false : true;
        do {
            result += to_string(abs(num % 7));
            num /= 7;
        } while (num);
        result += bNegative ? "-" : "";
        reverse(result.begin(), result.end());
        return result;
    }
};

*/

/** Python

class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        string=''

        n=abs(num)
        while n:
            string= str(n%7) +string
            n/=7
        if num>0:
            return string
        elif num<0:
            return '-'+string
        return '0'

*/
