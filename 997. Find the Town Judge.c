int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    int i, judge, number = 0, max = 0, index = 0;
    int *p_people = malloc(sizeof(int)*N);
    int *p_check = calloc(N,sizeof(int));
    if (N == 1)
        return 1;
    for (i = 0; i < N; i++)
        p_people[i] = i+1;
    for (i = 0; i < trustSize; i++) {
        p_people[*(*(trust+i)+0)-1] = -1;
        p_check[*(*(trust+i)+1)-1]++;
    }
    //printf("\n");
    for (i = 0; i < N; i++)
        if (p_people[i] != -1) {
            judge = p_people[i];
            number++;
        }
    for (i = 0; i < N; i++)
        if (p_check[i] > max) {
            max = p_check[i];
            index = i + 1;
            //printf("%d %d\n",i,max);
        }
    //printf("\n%d %d %d",judge,number,max);
    if ((!number || number > 1))
        return -1;
    else if ((judge == index))
        return judge;
    else
        return -1;
}


/** C++

auto __ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trustCount(N+1, 0);
        int i = 0;
        for(i = 0; i < trust.size(); i++){
            trustCount[trust[i][0]] -= 1; // Reduce trust dependency
            trustCount[trust[i][1]] += 1; // Improve trust count
        }

        for(i = 1; i < trustCount.size(); i++){
            if(trustCount[i] == N-1) return i;
        }
        return -1;
    }
};

/** Python

class Solution(object):
    def findJudge(self, N, trust):
        """
        :type N: int
        :type trust: List[List[int]]
        :rtype: int
        """

        '''
        [1, ...., N]

        A trusts B
        C trusts B
        B trustees = [A, C]
        '''

        x = set(range(1, N+1))
        for (a, b) in trust:
            if a in x:
                x.remove(a)
        if len(x) != 1:
            return -1

        judge_cand = list(x)[0]
        cnt_trust = 0
        for (a, b) in trust:
            if b == judge_cand:
                cnt_trust += 1

        if cnt_trust == N-1:
            return judge_cand
        return -1
