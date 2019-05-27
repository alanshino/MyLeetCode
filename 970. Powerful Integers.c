class Solution {
public:
    void expand(map<int, int> &ret, int x, int y, int bound, int base_x, int base_y)
    {
        int incr_x = base_x*x;
        int incr_y = base_y*y;
        int exp_x = incr_x + base_y;
        int exp_y = incr_y + base_x;
        if(exp_x<=bound && ret.count(exp_x)!=1){
            ret[exp_x] = 1;
            expand(ret, x, y, bound, incr_x, base_y);

        }
        if(exp_y<=bound && ret.count(exp_y)!=1){
            ret[exp_y] = 1;
            expand(ret, x, y, bound, base_x, incr_y);
        }
    }



    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans_vec;
        map<int, int>dict;
        int base_x = 1, base_y = 1;
        if (bound>=2)
        {

            dict[2] = 1;
            expand(dict, x, y, bound, base_x, base_y);

            for(map<int, int>::iterator iter = dict.begin(); iter != dict.end(); iter++)
            {
                ans_vec.push_back(iter->first);
            }
        }
        return ans_vec;
    }
};


/** C++

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int i(0), j(0);
        unordered_set<int> res;
        do {
            int xi = pow(x, i++);
            if (xi > bound) break;
            j = 0;
            do {
                int s = xi + pow(y, j++);
                if (s > bound) break;
                else res.insert(s);
            } while (y > 1);
        } while (x > 1);
        return vector<int>(res.begin(), res.end());
    }
};


class Solution {
public:
    int intlog(double base, double x) {
        return (int)(log(x) / log(base));
    }
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int xx=0,yy=0;
        if(x!=1)xx=intlog(x,bound);else xx=100;
        if(y!=1)yy=intlog(y,bound);else yy=100;

        set<int> ans;
        for(int i=0;i<=xx;i++)
            for(int j=0;j<=yy;j++)
                    if(pow(x,i)+pow(y,j)<=bound)ans.insert(pow(x,i)+pow(y,j));
        vector<int> ans1(ans.begin(),ans.end());
        return ans1;
    }
};
