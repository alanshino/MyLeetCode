int maxNumberOfBalloons(char * text){
    char *pc = "balloon";                // 為題目給定的字串
    int balloon[26] = {0};
    int temp = 0;                        // 用來記錄多少個 "balloon" 的組合
    while (*text) {                      // 先將所有字元單獨拆解出來成元素個別組合數
        balloon[*text - 'a']++;
        text++;
    }
    /*for (int i = 0; i < 26; i++) {
        if (balloon[i] && (balloon[i] % balloon1[i] == 0)) {
            temp = balloon[i];
            answer = balloon[i];
        }
        if ()
    }*/
    if (balloon['b' - 'a'] && balloon[0] && balloon['l' - 'a'] && balloon['o' - 'a'] && balloon['n' - 'a']) {  // 確認符合字串的元素都存在
        while (balloon['b' - 'a'] && balloon[0] && balloon['l' - 'a'] > 1 && balloon['o' - 'a'] > 1 && balloon['n' - 'a']) { // 開始 loop 每次都判斷是否有符合字串的元素存在
            balloon['b' - 'a']--;                       // 依各元素的出現次數作減運算 , 以此即可組合出一個符合題意的字串
            balloon[0]--;
            balloon['n' - 'a']--;
            balloon['l' - 'a'] -= 2;
            balloon['o' - 'a'] -= 2;
            if (balloon['b' - 'a'] && balloon[0] && balloon['l' - 'a'] && balloon['o' - 'a'] && balloon['n' - 'a'])  // 這行判斷是多餘的 , 直接增加或回傳當前值即可
                temp++;
            else
                return temp;
        }
    }else {
        return 0;
    }
    return 0;
}

/** C correct
int maxNumberOfBalloons(char * text){
    char *pc = "balloon";
    int balloon[26] = {0};
    int temp = 0;
    while (*text) {
        balloon[*text - 'a']++;
        text++;
    }
    if (balloon['b' - 'a'] && balloon[0] && balloon['l' - 'a'] && balloon['o' - 'a'] && balloon['n' - 'a']) {
            while (balloon['b' - 'a'] && balloon[0] && balloon['l' - 'a'] > 1 && balloon['o' - 'a'] > 1 && balloon['n' - 'a']) {
                balloon['b' - 'a']--;
                balloon[0]--;
                balloon['n' - 'a']--;
                balloon['l' - 'a'] -= 2;
                balloon['o' - 'a'] -= 2;
                temp++;
            }
            return temp;
    }else {
        return 0;
    }
    return 0;
}
*/
