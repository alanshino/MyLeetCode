int countCharacters(char ** words, int wordsSize, char * chars){
    int a[26] = {0}, tag, number = 0;             // ���O�ΨӰO�����w�r�ꪺ�r���Ӽ� , ���� , �l���X�ƥ�
    char *pc = NULL;
    int *pb = calloc(wordsSize, sizeof(int));     // �ΨӰO���l���X������
    int **pa = malloc(sizeof(int *) * wordsSize); // �ΨӬ����ާ@�r�ꪺ�r���Ӽ�
    for (int i = 0; i < wordsSize; i++) {
        pa[i] = calloc(26, sizeof(int));          // ���t�Ŷ�
        pc = words[i];
        while (*pc) {
            pa[i][*pc - 'a']++;                   // �r���ӼƬ���
            pc++;
        }
    }
    while (*chars) {
        a[*chars - 'a']++;
        chars++;
    }
   /* for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < 26; j++) {
            printf("%d ", pa[i][j]);
        }
        printf("\n");
    } */
    for (int i = 0; i < wordsSize; i++) {  // �ΨӧP�w�O�_�۵� , �å� tag �@���аO
        tag = 0;
        for (int j = 0; j < 26; j++) {
            if (pa[i][j] > a[j]) {
                tag = 1;
                break;
            }
        }
        if (!tag) {
            pb[i] = 1;
            number++;
        }
    }
 /*   for (int i = 0; i < wordsSize; i++) {
        printf("%d ", pb[i]);
    } */
    tag = 0;
    for (int i = 0; i < wordsSize; i++) {  // �]���D�حn���O�ۦP�l���X���r���`��
        if (pb[i]) {
            tag += strlen(words[i]);       // �I�s strlen function �ӭp��r����
        }
    }
    return tag;
}

/** C++

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <list>
#include <math.h>

using namespace std;

static int my_speed_up = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#ifdef MyTreeNode
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif


#define COMMA << ", " <<



class Solution
{
public:
    int countCharacters(vector<string>& words, string chars)
    {
        vector<int> ch_count (26, 0);

        for (auto ch : chars)
            ++ch_count[(int)(ch - 'a')];

        int sum_len = 0;
        for (auto &word : words)
        {
            vector<int> ch_count_i (26, 0);
            bool is_valid = true;
            for (auto ch : word)
            {
                int idx = ch - 'a';

                ++ch_count_i[idx];

                if (ch_count_i[idx] > ch_count[idx])
                {
                    is_valid = false;
                    break;
                }
            }

            if (is_valid)
                sum_len += word.length();
        }

        return sum_len;
    }
};


class Solution {

public:
    int countCharacters(vector<string>& words, string chars) {
        ios::sync_with_stdio(false);
        int result=0;
        int n=words.size();
        int charsLen=chars.size();
        vector<int> charsCon(26,0);
        for(int i=0;i<charsLen;++i){
            ++charsCon[chars[i]-97];
        }
        for(int i=0;i<n;++i){
            vector<int> tempCon(26,0);
            bool can=true;
            int length=words[i].size();
            for(int j=0;j<length;++j){
                int index=words[i][j]-97;
                if(++tempCon[index]>charsCon[index]){
                    can=false;
                    break;
                }
            }
            if(can) result+=length;
        }
        return result;
    }
};

int _ = []() { ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); return 0; }();

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        std::vector<int> alphabet(26);
        for(auto ch : chars) ++alphabet[ch - 'a'];

        int len = 0;
        for(auto word : words) {
            auto borrow = alphabet;
            bool can_make = true;
            for(auto letter : word) {
                if(borrow[letter - 'a'] <= 0) {
                    can_make = false;
                    break;
                }
                --borrow[letter - 'a'];
            }
            if(can_make) len += word.size();
        }
        return len;
    }
};

*/
