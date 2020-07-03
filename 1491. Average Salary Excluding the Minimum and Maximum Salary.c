/* 1491. Average Salary Excluding the Minimum and Maximum Salary */
/**
 * Given an array of unique integers salary where salary[i] is the salary of the employee i.
 * Return the average salary of employees excluding the minimum and maximum salary.
 * Example 1:
 * Input: salary = [4000,3000,1000,2000]
 * Output: 2500.00000
 * Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
 * Average salary excluding minimum and maximum salary is (2000+3000)/2= 2500
 * Example 2:
 * Input: salary = [1000,2000,3000]
 * Output: 2000.00000
 * Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
 * Average salary excluding minimum and maximum salary is (2000)/1= 2000
 * Example 3:
 * Input: salary = [6000,5000,4000,3000,2000,1000]
 * Output: 3500.00000
 * Solution
 * 找出員工的平均薪資，但不包含最高及最低
 */

double average(int* salary, int salarySize){
    int max = 0;
    int min = 1000000;             // 最高薪資上限
    int max_index;
    int min_index;
    for (int i = 0; i < salarySize; i++) { // 記下最高跟最低薪資的註標
        if (salary[i] > max) {
            max = salary[i];
            max_index = i;
        }
        if (salary[i] < min) {
            min = salary[i];
            min_index = i;
        }
    }
    max = 0;
    for (int i = 0; i < salarySize; i++) { // 最高、最低不列入計算，其餘平均即可
        if (i == max_index || i == min_index) {
            ;
        } else {
            max += salary[i];
        }
    }
    return (double)max / (salarySize - 2);
}
