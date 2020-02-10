/**
Given a non-negative integer num, return the number of steps to reduce it to zero.
If the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
題目給定一個非負整數num，返回將其減少為零的步驟數。如果當前數字為偶數，則必須將其除以2，否則，必須從中減去1。

Example:
Input: num = 14
Output: 6
Explanation:
Step 1) 14 is even; divide by 2 and obtain 7.
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3.
Step 4) 3 is odd; subtract 1 and obtain 2.
Step 5) 2 is even; divide by 2 and obtain 1.
Step 6) 1 is odd; subtract 1 and obtain 0.

Input: num = 8
Output: 4
Explanation:
Step 1) 8 is even; divide by 2 and obtain 4.
Step 2) 4 is even; divide by 2 and obtain 2.
Step 3) 2 is even; divide by 2 and obtain 1.
Step 4) 1 is odd; subtract 1 and obtain 0.
*/

int numberOfSteps (int num){
    int steps = 0;                   // 儲存操作的步驟數
    while (num) {
        if (num % 2) {               // 遇到奇數做-1
            num--;
        }else {                      // 偶數則除2
            num /= 2;
        }
        steps++;
    }
    return steps;
}
