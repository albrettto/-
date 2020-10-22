#include <iostream>
using namespace std;

class Point {
public:
    int x, y;
    Point() {
        x = 0;
        y = 0;
        printf("Конструктор Point(). (x = %i; y = %i)\n", x, y);
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
        printf("Конструктор Point(int x, int y). (x = %i; y = %i)\n", x, y);
    }
    Point(const Point &p) {
        x = p.x;
        y = p.y;
        printf("Конструктор Point(const Point &p). (x = %i; y = %i)\n", x, y);
    }
    ~Point() {
        printf("Деструткор ~Point(). (x = %i; y = %i) \n",x , y);
    }
    void reset();
    void move(int a, int b) {
        x += a;
        y += b;
        printf("Функция move. (x = %i; y = %i)\n", x, y);
    }
};

void Point::reset() {
    x = 0;
    y = 0;
    printf("Функция reset. (x = %i; y = %i)\n", x, y);
}

class Line{
public:    
    Point *p1;
    Point *p2;

    Line() {
        p1 = new Point;
        p2 = new Point;
        printf("Line()\n");
    }
    Line(int x1, int y1, int x2, int y2) {
        p1 = new Point(x1,y1);
        p2 = new Point(x2,y2);
        printf("Line(int x1, int y1, int x2, int y2)\n");
    }
    Line(const Line &l){
        p1 = new Point(*(l.p1));
        p2 = new Point(*(l.p2));
        printf("Line(const Line &l)\n");
    }
    ~Line() {
        delete p1;
        delete p2;
        printf("~Line\n");
    }
    double get_length(const Line &l) {
        int a = (l.p2->x - l.p1->x) * (l.p2->x - l.p1->x);
        int b = (l.p2->y - l.p1->y) * (l.p2->y - l.p1->y);
        double L = sqrt(a+b);
        return L; 
    }
};

int main()
{
    setlocale(0, "");
    {
        int x = 1, y = 2;
        Point p1;
        Point p2(x, y);
        Point p3(p2);
        p3.reset();
        p3.move(5, 6);
    }
    cout << "\n\n\n\n";
    {
        int x1 = 1, y1 = 2, x2 = 3, y2 = 4;
        Line* l = new Line;
        Line *l1 = new Line(x1, y1, x2, y2);
        Line *l2 = new Line(*l1);
        cout << "Длина прямой l1 = " << l1->get_length(*l1) << endl;
        delete l;
        delete l1;
        delete l2;
    }
    return 0;
}