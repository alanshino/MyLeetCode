/**
 * Given an integer n,
 * return a string with n characters such that each character in such string occurs an odd number of times.
 * The returned string must contain only lowercase English letters. If there are multiples valid strings, return any of them.
 * Example:
    Input: n = 4
    Output: "pppz"
    Explanation: "pppz" is a valid string since the character 'p' occurs three times and the character 'z' occurs once.
    Note that there are many other valid strings such as "ohhh" and "love".
 * Example:
    Input: n = 2
    Output: "xy"
    Explanation: "xy" is a valid string since the characters 'x' and 'y' occur once.
    Note that there are many other valid strings such as "ag" and "ur".
 * ���D�覡: �D�ث��n�D�^�ǩ_�ƪ��r���Φ��A�å�����ϥΪ��r���C
             ���D�ة��ӧP�_�ӧ@�A����-1���o���ө_�ơC
             �䤤�@�Ӷ�J���N�r���A�t�@�Ӷ�J���ۦP�r���Y�i
 */

char * generateTheString(int n){
    char *preturn = malloc(sizeof(char) * n + 1);   // �n�O�o�O�d'\0'���Ŷ�
    int i = 0;
    if (n % 2) {
        for (i = 0; i < n; i++) {
            preturn[i] = 'a';                // �H'a'�ӧ@(�i�ۥѴ���)
        }
    }else {
        for (i = 0; i < n - 1; i++) {
            preturn[i] = 'a';
        }
        preturn[i++] = 'b';                 // ���N��ɪ��r���A�u�n���ۦP�Y�i
    }
    preturn[i] = '\0';
    return preturn;
}


