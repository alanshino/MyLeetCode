int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    int clockwiseValue = 0, total = 0, temp = 0;                  // 分別保留順時針的距離 , 總距離 , 交換變數
    if (start > destination) {                                    // destination > start 代表從後面開回來
        temp = start;                                             // 所以將起始點與終點互換
        start = destination;
        destination = temp;
    }
    for (int i = start; i < destination; i++) {                   // 開始計算順時鐘距離
        clockwiseValue += distance[i];
    }
    for (int i = 0; i < distanceSize; i++) {                      // 計算總距離
        total += distance[i];
    }
    // printf("%d ", clockwiseValue);
    /*counterclockwiseValue = distance[distanceSize - 1];         // 原本想分別計算順時針與逆時針 , 後來發現不用這麼麻煩
    for (int i = distanceSize - 2; i >= destination; i--) {
        counterclockwiseValue += distance[i];
    }*/

    return (clockwiseValue > total - clockwiseValue)? total - clockwiseValue : clockwiseValue; // 如果順時針距離比較短就回傳這個距離 , 反之則回傳逆時針距離( 用總距離減去順時針距離來表示 )
    //return 0;
}

/**

A bus has n stops numbered from 0 to n - 1 that form a circle. We know the distance between all pairs of neighboring stops where distance[i] is the distance between the stops number i and (i + 1) % n.

The bus goes along both directions i.e. clockwise and counterclockwise.

Return the shortest distance between the given start and destination stops.

Input: distance = [1,2,3,4], start = 0, destination = 1
Output: 1
Explanation: Distance between 0 and 1 is 1 or 9, minimum is 1.

Input: distance = [1,2,3,4], start = 0, destination = 3
Output: 4
Explanation: Distance between 0 and 3 is 6 or 4, minimum is 4.

*/
