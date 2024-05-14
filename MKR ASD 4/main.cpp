#include <iostream>

using namespace std;

// Function to determine the orientation of three points (p, q, r)
int orientation(int x1, int y1, int x2, int y2, int x3, int y3) {
    int val = (y2 - y1) * (x3 - x2) - (x2 - x1) * (y3 - y2);
    if (val == 0) return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Function to check if two segments intersect
bool doIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int o1 = orientation(x1, y1, x2, y2, x3, y3);
    int o2 = orientation(x1, y1, x2, y2, x4, y4);
    int o3 = orientation(x3, y3, x4, y4, x1, y1);
    int o4 = orientation(x3, y3, x4, y4, x2, y2);

    // If the orientations of the points are different, the segments intersect
    if (o1 != o2 && o3 != o4) return true;
    return false;
}

int main() {
    // Coordinates of the endpoints of segments AB and CD
    int x1 = 1, y1 = 1, x2 = 10, y2 = 1; // Segment AB
    int x3 = 5, y3 = 0, x4 = 5, y4 = 2;  // Segment CD

    if (doIntersect(x1, y1, x2, y2, x3, y3, x4, y4))
        cout << "Segments intersect\n";
    else
        cout << "Segments do not intersect\n";

    return 0;
}

