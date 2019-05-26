/** C  */

bool canThreePartsEqualSum(int* A, int ASize) {
    int total=0,i,partition=0,sum=0;
    for (i=0;i<ASize;i++) {
        total+=*(A+i);
    }
    if (total%3)
        return 0;
    total=total/3;
    for (i=0;i<ASize;i++) {
        sum+=*(A+i);
        if (sum==total) {
            sum=0;
            partition++;
        }
    }
    if (partition==3)
        return 1;
    else
        return 0;
}

bool canThreePartsEqualSum(int* A, int ASize) {
    int total=0,sum=0,cnt=0;
    for(int i=0;i<ASize;i++)
        total+=A[i];
    if(total%3!=0) return false;
    for(int i=0;i<ASize&&cnt<(total!=0?2:3);i++)
    {
        sum+=A[i];
        if(sum==total/3)
        {
            cnt++;
            sum=0;
        }
    }
    if(cnt==(total!=0?2:3))return true;
    else return false;
}

bool canThreePartsEqualSum(int* A, int ASize) {

    int i,sum=0,s1,s2,ind1=-1,ind2=-1,s=0;

    for(i=0;i<ASize;i++)
        sum+=A[i];

    if(sum%3!=0) return false;

    s1=sum/3;
    s2=2*s1;

    for(i=0;i<ASize;i++)
    {
        s+=A[i];
        if(s==s1 && ind1==-1 && s!=0)
            ind1=i;
        else
            if(s==s2 && s!=0 && ind1!=-1)
            {
                ind2=i;
                break;
            }

    }

    if (ind1!=-1 && ind2!=-1)
        return true;
    else
        return false;
}


/** Python

class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        sums = sum(A)
        if sums % 3 != 0:   return False
        l, r = 0, sums
        for i in xrange(len(A)):
            l += A[i]
            r -= A[i]
            if l * 2 == r:
                b = 0
                for j in xrange(i+1, len(A)):
                    b += A[j]
                    if b == l:  return True
        return False

class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        total = sum(A)
        if total % 3 != 0:
            return False
        target = total // 3
        prefix = 0
        goal = [target * 2, target]
        for a in A:
            prefix += a
            if prefix == goal[-1]:
                goal.pop()
            if not goal:
                return True
        return False
