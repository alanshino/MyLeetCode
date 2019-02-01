int trailingZeroes(int n) {
    return n < 5 ? 0 : n /5 + trailingZeroes(n / 5);    // 以 5 為階數,遇到就加上次數
}

/** Java
public class Solution {
    public int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
}
*/

/**Python
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        trailing = 0
        while n>=5:
            n//=5
            trailing += n
        return trailing
*/
