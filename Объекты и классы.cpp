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

class ColoredLine : public Line {
private:
    string color;
public:
    ColoredLine(): Line() {
        color = "черный";
        printf("Конструктор ColoredLine(): Line(). color = %s\n", color);
    }
    ColoredLine(string color, int x1, int y1, int x2, int y2) : Line(x1,y1,x2,y2) {
        this->color = color;
        printf("Конструктор ColoredLine(string color, int x1, int y1, int x2, int y2) : Line(x1,y1,x2,y2). color = %s\n", color);
    }
    ColoredLine(const ColoredLine & l_){
        color = l_.color;
        p1 = new Point(*(l_.p1));
        p2 = new Point(*(l_.p2));
        /*this->p1 = l_.p1;
        this->p2 = l_.p2;*/
        printf("Конструктор ColoredLine(string color, int x1, int y1, int x2, int y2) : Line(x1,y1,x2,y2). color = %s)\n", color);
    }
    ~ColoredLine() {
        printf("Деструктор ~ColoredLine()\n");
       /* delete p1;
        delete p2;*/
    }
};

void show(int i){ printf("\n%i)\n", i); }

int main()
{
    int i = 1;
    /*SetConsoleCP(1251);
    SetConsoleOutputCP(1251);*/
    setlocale(LC_ALL, "Russian"); // задаём русский текст
    //system("chcp 1251"); // настраиваем кодировку консоли

    printf("\t\tДемонстрация класса Point:\n");
    {
        int x = 1, y = 2;
        show(i++);
        Point p1;
        show(i++);
        Point p2(x, y);
        show(i++);
        Point p3(p2);
        show(i++);
        p3.reset();
        show(i++);
        p3.move(5, 6);
        show(i++);
    }
    printf("\n\t\tДемонстрация класса Line:\n");
    {
        int x1 = 1, y1 = 2, x2 = 3, y2 = 4;
        show(i++);
        Line* l = new Line;
        show(i++);
        Line *l1 = new Line(x1, y1, x2, y2);
        show(i++);
        Line *l2 = new Line(*l1);
        show(i++);
        l1->get_length(*l1);
        show(i++);
        delete l;
        show(i++);
        delete l1;
        show(i++);
        delete l2;
    }
    printf("\n\t\tДемонстрация класса ColoredLine:\n");
    {
        int x1 = 5, y1 = 6, x2 = 6, y2 = 5;
        string color = "красный";
        show(i++);
        ColoredLine* l_1 = new ColoredLine;
        show(i++);
        ColoredLine *l_2 = new ColoredLine(color, x1, y1, x2, y2);
        show(i++);
        ColoredLine *l_3 = new ColoredLine(*l_2);
        show(i++);
        delete l_1;
        show(i++);
        delete l_2;
        show(i++);
        delete l_3;
    }
    printf("\n\t\tДемонстрация помещения класса ColoredLine в класс-предок :\n");
    {
        show(i++);
        Line* l = new ColoredLine("голубой", 1, 2, 3, 4); 
        show(i++);
        delete l;
    }
    system("pause");
    return 0;
}