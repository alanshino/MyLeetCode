int maxNumberOfBalloons(char * text){
    char *pc = "balloon";                // ���D�ص��w���r��
    int balloon[26] = {0};
    int temp = 0;                        // �ΨӰO���h�֭� "balloon" ���զX
    while (*text) {                      // ���N�Ҧ��r����W��ѥX�Ӧ������ӧO�զX��
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
    if (balloon['b' - 'a'] && balloon[0] && balloon['l' - 'a'] && balloon['o' - 'a'] && balloon['n' - 'a']) {  // �T�{�ŦX�r�ꪺ�������s�b
        while (balloon['b' - 'a'] && balloon[0] && balloon['l' - 'a'] > 1 && balloon['o' - 'a'] > 1 && balloon['n' - 'a']) { // �}�l loop �C�����P�_�O�_���ŦX�r�ꪺ�����s�b
            balloon['b' - 'a']--;                       // �̦U�������X�{���Ƨ@��B�� , �H���Y�i�զX�X�@�ӲŦX�D�N���r��
            balloon[0]--;
            balloon['n' - 'a']--;
            balloon['l' - 'a'] -= 2;
            balloon['o' - 'a'] -= 2;
            if (balloon['b' - 'a'] && balloon[0] && balloon['l' - 'a'] && balloon['o' - 'a'] && balloon['n' - 'a'])  // �o��P�_�O�h�l�� , �����W�[�Φ^�Ƿ�e�ȧY�i
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
