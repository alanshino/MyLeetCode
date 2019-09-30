int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    int clockwiseValue = 0, total = 0, temp = 0;                  // ���O�O�d���ɰw���Z�� , �`�Z�� , �洫�ܼ�
    if (start > destination) {                                    // destination > start �N��q�᭱�}�^��
        temp = start;                                             // �ҥH�N�_�l�I�P���I����
        start = destination;
        destination = temp;
    }
    for (int i = start; i < destination; i++) {                   // �}�l�p�ⶶ�����Z��
        clockwiseValue += distance[i];
    }
    for (int i = 0; i < distanceSize; i++) {                      // �p���`�Z��
        total += distance[i];
    }
    // printf("%d ", clockwiseValue);
    /*counterclockwiseValue = distance[distanceSize - 1];         // �쥻�Q���O�p�ⶶ�ɰw�P�f�ɰw , ��ӵo�{���γo��·�
    for (int i = distanceSize - 2; i >= destination; i--) {
        counterclockwiseValue += distance[i];
    }*/

    return (clockwiseValue > total - clockwiseValue)? total - clockwiseValue : clockwiseValue; // �p�G���ɰw�Z������u�N�^�ǳo�ӶZ�� , �Ϥ��h�^�ǰf�ɰw�Z��( ���`�Z����h���ɰw�Z���Ӫ�� )
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
