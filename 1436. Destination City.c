/** 1436. Destination City */
/**
 * You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi.
 * Return the destination city, that is, the city without any path outgoing to another city.
 * It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.
 *
 * Example 1
 * Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
 * Output: "Sao Paulo"
 * Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city.
 * Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
 *
 * Example 2
 * Input: paths = [["B","C"],["D","B"],["C","A"]]
 * Output: "A"
 * Explanation: All possible trips are:
 * "D" -> "B" -> "C" -> "A".
 * "B" -> "C" -> "A".
 * "C" -> "A".
 * "A".
 * Clearly the destination city is "A".
 *
 * Example 3
 * Input: paths = [["A","Z"]]
 * Output: "Z"
 */

/*
  Solution:
  最終目的地城市必須是唯一的，所以如果在出發地找到相同的城市，就說明並非是最終目的地。
  依序比較目的地跟出發地，以此找出最終地點。
*/
int same_string(char *a, char *b);

char * destCity(char *** paths, int pathsSize, int* pathsColSize){
    int counter = 0;                                      // 紀錄不相同之字串數
    for (int i = 0; i < pathsSize; i++) {
        for (int j = 0; j < pathsSize; j++) {
            if (i == j)
                continue;
            else {
                if (same_string(paths[i][1], paths[j][0])) {
                    counter++;
                } else {
                    counter = 0;
                    break;
                }
            }
            if (counter == pathsSize - 1) {
                return paths[i][1];
            }
        }
    }

    return paths[0][1];
}

int same_string(char *a, char *b)
{
    int length_a = strlen(a);
    int length_b = strlen(b);
    if (length_a != length_b) {
        return 1;
    } else {
        while (*a && *b) {
            if (*a != *b)
                return 1;
            a++;
            b++;
        }
        return 0;
    }
}

// another solution
/*
char * destCity(char *** paths, int pathsSize, int* pathsColSize){
    int i, j;

    for(i = 0; i < pathsSize; i++) {
        for(j = 0; j < pathsSize; j++) {
            if(!strcmp(paths[i][1], paths[j][0]))
                break;
        }
        if(j == pathsSize)
            return paths[i][1];
    }
    return NULL;
}
*/
