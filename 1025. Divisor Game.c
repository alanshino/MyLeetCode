/** C  */

bool findIt(int N,int ch)
{
    int i=1;
    if(N==1)
    {
        if(ch==0)
            return false;
        else
            return true;
    }
    for(i;i<N;i++)
    {
        if(N%i==0)
        {
            return findIt(N-i,ch^1);
        }
    }
    return false;
}
bool divisorGame(int N){
    return findIt(N,0);
}

/** C++ */

class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};

class Solution {
public:
    bool divisorGame(int N) {
       if(N%2)
        return false;
        return true;
    }
};

/** Java  */

class Solution {
    private static int[] record = new int[1001];
    static {
        record[1] = -1;
        record[2] = 1;
    }
    public boolean divisorGame(int N) {
        if (N < 1 || N > 1000) return false;
        if (record[N] != 0)
            return record[N]==1;
        for (int i = N/2; i>0; i--)
            if (N % i == 0)
                if (record[N-i] == -1 ||
                   (record[N-i] == 0 && !divisorGame(N-i))) {
                    record[N] = 1;
                    return true;
                }
        record[N] = -1;
        return false;
    }
}

class Solution {
    public boolean divisorGame(int N) {
        return N % 2 == 0;
    }
}


/** Python  */

class Solution(object):
    def divisorGame(self, N):
        """
        :type N: int
        :rtype: bool
        """
        return N % 2 == 0

class Solution(object):
    def divisorGame(self, N):
        count, x = 0, 1
        while N > 1:
            N, count = N - x, count + 1
            if N == 1:
                if count % 2 == 0: return False
                else: return True
