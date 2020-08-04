/**
 * problem: 1528. Shuffle String
 * Given a string s and an integer array indices of the same length.
 * The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.
 * Return the shuffled string.
 * Example 1:
   Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
   Output: "leetcode"
   Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
 * Example 2:
   Input: s = "abc", indices = [0,1,2]
   Output: "abc"
   Explanation: After shuffling, each character remains in its position.
 * Example 3:
   Input: s = "aiohn", indices = [3,1,4,2,0]
   Output: "nihao"
 * Solution
   重新分配一個陣列，直接將元素指定的位置放入即可
*/
char * restoreString(char * s, int* indices, int indicesSize){
    char *preturn = malloc(sizeof(char) * (indicesSize + 1));
    int i;
    for (i = 0; i < indicesSize; i++) {
        preturn[indices[i]] = s[i];  // 元素指定位置
    }
    preturn[i] = 0;
    return preturn;
}
