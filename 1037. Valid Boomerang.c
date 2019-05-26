/** C

bool isBoomerang(int** points, int pointsSize, int* pointsColSize) {
    return (points[1][1] - points[0][1]) * (points[2][0] - points[1][0]) != (points[2][1] - points[1][1]) * (points[1][0] - points[0][0]);
}

bool isBoomerang(int** points, int pointsSize, int* pointsColSize)
{
    if ((points[0][0] == points[1][0] && points[0][1] == points[1][1]) ||
        (points[0][0] == points[2][0] && points[0][1] == points[2][1]) ||
        (points[1][0] == points[2][0] && points[1][1] == points[2][1]))
    {
        return false;
    }

    if ((float)(points[1][1] - points[0][1]) / (points[1][0] - points[0][0]) == (float)(points[2][1] - points[0][1]) / (points[2][0] - points[0][0]))
    {

        return false;
    }
    return true;
}

bool isBoomerang(int** points, int pointsSize, int* pointsColSize) {
    int dx1 = points[1][0] - points[0][0], dy1 = points[1][1] - points[0][1];
    int dx2 = points[2][0] - points[0][0], dy2 = points[2][1] - points[0][1];
    return dx1 * dy2 != dx2 *dy1;
}

*/
