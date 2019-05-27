/**

    先找出 'R' 的位置後按四個方位前進

*/

int numRookCaptures(char** board, int boardRowSize, int boardColSize) {
    int queen[2], i, j, die = 0, go_down, go_right, go_left, go_up;
    int B_chess[2] = {0, -1}, P_chess[2] = {0, -1};
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] == 'R') {
                queen[0] = i;
                queen[1] = j;
                break;
            }
        }
    }
    go_down = 7 - queen[0];
    go_right = 7 - queen[1];
    go_up = queen[0] - 0;
    go_left = queen[1] - 0;
    if (go_down) {
        for (i = queen[0] + 1, j = queen[1]; i < 8; i++) {
            if (board[i][j] == 'B') {
                B_chess[0] = i;
                B_chess[1] = 1;
                break;
            }
        }
        for (i = queen[0] + 1, j = queen[1]; i < 8; i++) {
            if (board[i][j] == 'p') {
                P_chess[0] = i;
                P_chess[1] = 1;
                break;
            }
        }
        /*if (B_chess[0] < P_chess[0] && B_chess[1] != -1)
            ;
        else if (P_chess[0] < B_chess[0] && P_chess[1] != -1)
            die++;*/
        if (B_chess[1] == 1) {
            if (B_chess[0] < P_chess[0])
                ;
            else if (P_chess[1] == 1)
                die++;
        }
        else if (P_chess[1] == 1)
            die++;
    }
    printf("%d ",die);
    B_chess[0] = 0;
    B_chess[1] = -1;
    P_chess[0] = 0;
    P_chess[1] = -1;
    if (go_right) {
        for (i = queen[1] + 1, j = queen[0]; i < 8; i++) {
            if (board[j][i] == 'B') {
                B_chess[0] = i;
                B_chess[1] = 1;
                break;
            }
        }
        for (i = queen[1] + 1, j = queen[0]; i < 8; i++) {
            if (board[j][i] == 'p') {
                P_chess[0] = i;
                P_chess[1] = 1;
                break;
            }
        }
        /*if (B_chess[0] < P_chess[0] && B_chess[1] != -1)
            ;
        else if (P_chess[0] < B_chess[0] && P_chess[1] != -1)
            die++;*/
        if (B_chess[1] == 1) {
            if (B_chess[0] < P_chess[0])
                ;
            else if (P_chess[1] == 1)
                die++;
        }
        else if (P_chess[1] == 1)
            die++;
    }
    printf("%d ",die);
    B_chess[0] = 0;
    B_chess[1] = -1;
    P_chess[0] = 0;
    P_chess[1] = -1;
    if (go_up) {
        for (i = queen[0], j = queen[1]; i >= 0; i--) {
            if (board[i][j] == 'B') {
                B_chess[0] = i;
                B_chess[1] = 1;
                break;
            }
        }
        for (i = queen[0], j = queen[1]; i >= 0; i--) {
            if (board[i][j] == 'p') {
                P_chess[0] = i;
                P_chess[1] = 1;
                break;
            }
        }
        if (B_chess[1] == 1) {
            if (B_chess[0] > P_chess[0])
                ;
            else if (P_chess[1] == 1)
                die++;
        }
        else if (P_chess[1] == 1)
            die++;
    }
    printf("%d ",die);
    B_chess[0] = 0;
    B_chess[1] = -1;
    P_chess[0] = 0;
    P_chess[1] = -1;
    if (go_left) {
        for (i = queen[0], j = queen[1]; j >= 0; j--) {
            if (board[i][j] == 'B') {
                B_chess[0] = j;
                B_chess[1] = 1;
                break;
            }
        }
        for (i = queen[0], j = queen[1]; j >= 0; j--) {
            if (board[i][j] == 'p') {
                P_chess[0] = j;
                P_chess[1] = 1;
                break;
            }
        }
        //printf("%d %d",P_chess[0],B_chess[0]);
        if (B_chess[1] == 1) {
            if (B_chess[0] > P_chess[0])
                ;
            else if (P_chess[1] == 1)
                die++;
        }
        else if (P_chess[1] == 1)
            die++;
    }
    printf("%d ",die);
    return die;
}


/** C++

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& b) {
        const vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int ret=0;
        for (auto i = 0; i < b.size(); ++i)
            for (auto j = 0; j < b[i].size(); ++j)
                if (b[i][j] == 'R'){
                    for(const auto [dx,dy]:dir){
                        int x=i,y=j;
                        while (x >= 0 && x < b.size() && y >= 0 && y < b[x].size() && b[x][y] != 'B'){
                            if (b[x][y] == 'p'){
                                ++ret;
                                break;
                            }
                            x += dx;
                            y += dy;
                        }
                    }
                    break;
                }
        return ret;
    }
};

