#include <iostream>
using namespace std;

class Point {
public:
    int x, y;
    Point() {
        x = 0;
        y = 0;
        printf("Point()\n");
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
        printf("Point(int x, int y)\n");
    }
    Point(const Point &p) {
        x = p.x;
        y = p.y;
        printf("Point(const Point &p)\n");
    }
    ~Point() {
        printf("x = %i; y = %i; ~Point()\n",x , y);
    }
};

int main()
{
    int x = 1, y = 2;
    Point p1;
    Point p2(x, y);
    Point p3(p2);
    return 0;
}