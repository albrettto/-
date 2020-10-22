#include <iostream>
#include <windows.h>
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
protected:    
    Point *p1;
    Point *p2;
public:
    Line() {
        p1 = new Point;
        p2 = new Point;
        printf("Конструктор Line(). p1(%i, %i), p2(%i, %i)\n", p1->x, p1->y, p2->x, p2->y);
    }
    Line(int x1, int y1, int x2, int y2) {
        p1 = new Point(x1,y1);
        p2 = new Point(x2,y2);
        printf("Конструктор Line(int x1, int y1, int x2, int y2). p1(%i, %i), p2(%i, %i)\n", p1->x, p1->y, p2->x, p2->y);
    }
    Line(const Line &l){
        p1 = new Point(*(l.p1));
        p2 = new Point(*(l.p2));
        printf("Конструктор Line(const Line &l). p1(%i, %i), p2(%i, %i)\n", p1->x, p1->y, p2->x, p2->y);
    }
    ~Line() {
        printf("Деструктор ~Line(). p1(%i, %i), p2(%i, %i)\n", p1->x, p1->y, p2->x, p2->y);
        delete p1;
        delete p2;
    }
    void get_length(const Line &l) {
        int a = (l.p2->x - l.p1->x) * (l.p2->x - l.p1->x);
        int b = (l.p2->y - l.p1->y) * (l.p2->y - l.p1->y);
        double L = sqrt(a+b);
        cout << "Длина прямой l1 = " << L << endl;;
    }
};

class ColoredLine : Line {
public:
    string color;
    ColoredLine(): Line() {
        color = "черный";
        printf("Конструктор ColoredLine(): Line(). color = %s\n", color);
    }
    ColoredLine(string color, int x1, int y1, int x2, int y2) : Line(x1,y1,x2,y2) {
        this->color = color;
        printf("Конструктор ColoredLine(string color, int x1, int y1, int x2, int y2) : Line(x1,y1,x2,y2). color = %s\n", color);
    }
    ColoredLine(const ColoredLine & l_) : Line(l_) {
        color = l_.color;
        p1 = new Point(*(l_.p1));
        p2 = new Point(*(l_.p2));
        printf("Конструктор ColoredLine(string color, int x1, int y1, int x2, int y2) : Line(x1,y1,x2,y2). color = %s)\n", color);
    }
    ~ColoredLine() {
        printf("Деструктор ~ColoredLine()");
    }
};

int main()
{
    int i = 1;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    {
        int x = 1, y = 2;
        printf("\n%i)\n", i++);
        Point p1;
        printf("\n%i)\n", i++);
        Point p2(x, y);
        printf("\n%i)\n", i++);
        Point p3(p2);
        printf("\n%i)\n", i++);
        p3.reset();
        printf("\n%i)\n", i++);
        p3.move(5, 6);
        printf("\n%i)\n", i++);
    }
    {
        int x1 = 1, y1 = 2, x2 = 3, y2 = 4;
        printf("\n%i)\n", i++);
        Line* l = new Line;
        printf("\n%i)\n", i++);
        Line *l1 = new Line(x1, y1, x2, y2);
        printf("\n%i)\n", i++);
        Line *l2 = new Line(*l1);
        l1->get_length(*l1);
        printf("\n%i)\n", i++);
        delete l;
        printf("\n%i)\n", i++);
        delete l1;
        printf("\n%i)\n", i++);
        delete l2;
    }
    {
        printf("\n%i)\n", i++);
        ColoredLine l_1;
        printf("\n%i)\n", i++);
        ColoredLine l_2("красный", 1, 2, 3, 4);
        printf("\n%i)\n", i++);
        ColoredLine l_3(l_2);
    }


    return 0;
}