#include <iostream>
#include <windows.h>
using namespace std;

class Point {
public: // полностью публичные атрибуты, методы, доступные вне класса.
    int x, y;
    Point() { // конструктор без параметров
        x = 0;
        y = 0;
        printf("Конструктор Point(). (x = %i; y = %i)\n", x, y);
    }
    Point(int x, int y) { // конструктор с параметрами
        this->x = x;
        this->y = y;
        printf("Конструктор Point(int x, int y). (x = %i; y = %i)\n", x, y);
    }
    Point(const Point &p) { // конструктор копирования
        x = p.x;
        y = p.y;
        printf("Конструктор Point(const Point &p). (x = %i; y = %i)\n", x, y);
    }
    ~Point() { // деструктор
        printf("Деструткор ~Point(). (x = %i; y = %i) \n",x , y);
    }
    void reset(); // инициализая метода сброса координаты точки
    void move(int a, int b) { // метод для перемещения точки
        x += a;
        y += b;
        printf("Функция move. (x = %i; y = %i)\n", x, y);
    }
};

void Point::reset() { // реализация метода вне класса
    x = 0;
    y = 0;
    printf("Функция reset. (x = %i; y = %i)\n", x, y);
}

class Line{
protected: // атрибуты доступные только классу Line и его дочерним классам
    Point *p1;
    Point *p2;
public: 
    Line() { // конструктор без параметров
        p1 = new Point;
        p2 = new Point;
        printf("Конструктор Line(). p1(%i, %i), p2(%i, %i)\n", p1->x, p1->y, p2->x, p2->y);
    }
    Line(int x1, int y1, int x2, int y2) { // конструктор с параметрами
        p1 = new Point(x1,y1);
        p2 = new Point(x2,y2);
        printf("Конструктор Line(int x1, int y1, int x2, int y2). p1(%i, %i), p2(%i, %i)\n", p1->x, p1->y, p2->x, p2->y);
    }
    Line(const Line &l){ // конструктор копирования
        p1 = new Point(*(l.p1));
        p2 = new Point(*(l.p2));
        printf("Конструктор Line(const Line &l). p1(%i, %i), p2(%i, %i)\n", p1->x, p1->y, p2->x, p2->y);
    }
    ~Line() { // деструктор
        printf("Деструктор ~Line(). p1(%i, %i), p2(%i, %i)\n", p1->x, p1->y, p2->x, p2->y);
        delete p1;
        delete p2;
    }
    void get_length(const Line &l) { // метод, который находит длину прямой
        int a = (l.p2->x - l.p1->x) * (l.p2->x - l.p1->x);
        int b = (l.p2->y - l.p1->y) * (l.p2->y - l.p1->y);
        double L = sqrt(a+b);
        cout << "Длина прямой l1 = " << L << endl;;
    }
};

class ColoredLine : public Line { // дочерний класс класса Line
private: // color доступен только классу ColoredLine
    string color;
public:
    ColoredLine(): Line() { // конструктор без параметров
        color = "черный";
        printf("Конструктор ColoredLine(): Line(). color = %s\n", &color);
    }
    ColoredLine(string color, int x1, int y1, int x2, int y2) : Line(x1,y1,x2,y2) { // конструктор с параметрами
        this->color = color;
        printf("Конструктор ColoredLine(string color, int x1, int y1, int x2, int y2) : Line(x1,y1,x2,y2). color = %s\n", color);
    }
    ColoredLine(const ColoredLine & l_){ // конструктор копирования
        color = l_.color;
        p1 = new Point(*(l_.p1));
        p2 = new Point(*(l_.p2));

        printf("Конструктор ColoredLine(string color, int x1, int y1, int x2, int y2) : Line(x1,y1,x2,y2). color = %s\n", color);
    }
    ~ColoredLine() { // деструктор
        printf("Деструктор ~ColoredLine()\n");
    }
};

void show(int i){ printf("\n%i)\n", i); } // функция вывода нумерации

int main()
{
    int i = 1;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("\t\tДемонстрация класса Point:\n");
    {
        int x = 1, y = 2;
        show(i++);
        Point p1; // точка без параметров
        show(i++);
        Point p2(x, y); // точка с параметрами
        show(i++);
        Point p3(p2); // копия точки p2
        show(i++);
        p3.reset(); // сброс точки p3
        show(i++);
        p3.move(5, 6); // перемещение точки p3
        show(i++);
    }
    system("pause");
    system("cls");
    i = 1;
    printf("\t\tДемонстрация класса Line:\n");
    {
        int x1 = 1, y1 = 2, x2 = 3, y2 = 4;
        show(i++);
        Line* l = new Line; // динамически созданная линия без параметров
        show(i++);
        Line *l1 = new Line(x1, y1, x2, y2); // динамически созданная линия с параметрами
        show(i++);
        Line *l2 = new Line(*l1); // динамически созданная копия линии
        show(i++);
        l1->get_length(*l1); // длина линии l1
        show(i++);
        delete l; // вызов деструктора (удаление) 
        show(i++);
        delete l1; // вызов деструктора (удаление) 
        show(i++);
        delete l2; // вызов деструктора (удаление) 
    }
    system("pause");
    system("cls");
    i = 1;
    printf("\t\tДемонстрация класса ColoredLine:\n");
    {
        int x1 = 5, y1 = 6, x2 = 6, y2 = 5;
        string color = "красный";
        show(i++);
        ColoredLine* l_1 = new ColoredLine; // динамически созданная цветная линия без параметров
        show(i++);
        ColoredLine *l_2 = new ColoredLine(color, x1, y1, x2, y2); // динамически созданная цветная линия с параметрами
        show(i++);
        ColoredLine *l_3 = new ColoredLine(*l_2); // динамически созданная цветная копия линии
        show(i++);
        delete l_1; // вызов деструктора (удаление) 
        show(i++);
        delete l_2; // вызов деструктора (удаление) 
        show(i++);
        delete l_3; // вызов деструктора (удаление) 
    }
    system("pause");
    system("cls");
    i = 1;
    printf("\t\tДемонстрация помещения класса ColoredLine в класс-предок :\n");
    {
        show(i++);
        Line* l = new ColoredLine("голубой", 1, 2, 3, 4); // динамически созданная цветная линия в классе линии
        show(i++);
        delete l; // вызов деструктора (удаление) 
    }
    system("pause");
    return 0;
}