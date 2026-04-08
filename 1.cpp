#include <iostream>
#include <cmath>
#include <string>
using namespace std;


class Point
{
public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    void print() const
    {
        cout << "(" << x << ", " << y << ")";
    }
};

class Shape
{
public:
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual ~Shape() {}
};

class TwoDShape : public Shape
{
protected:
    string name;

public:
    TwoDShape(const string &name) : name(name) {}
    string getName() const { return name; }
    virtual ~TwoDShape() {}
};

class Circle : public TwoDShape
{
private:
    Point center;
    double radius;

public:
    Circle(const Point &c, double r, const string &n)
        : TwoDShape(n), center(c), radius(r) {}

    double getArea() const override
    {
        return M_PI * radius * radius;
    }

    double getPerimeter() const override
    {
        return 2 * M_PI * radius;
    }

    void print() const
    {
        cout << name << ": төв=";
        center.print();
        cout << ", r=" << radius;
        cout << ", S=" << getArea();
        cout << ", L=" << getPerimeter() << endl;
    }
};

class Square : public TwoDShape
{
private:
    Point vertices[4];
    double side;

public:
    Square(const Point &leftTop, double s, const string &n)
        : TwoDShape(n), side(s)
    {
        vertices[0] = leftTop;
        vertices[1] = Point(leftTop.x + side, leftTop.y);
        vertices[2] = Point(leftTop.x + side, leftTop.y + side);
        vertices[3] = Point(leftTop.x, leftTop.y + side);
    }

    double getArea() const override
    {
        return side * side;
    }

    double getPerimeter() const override
    {
        return 4 * side;
    }

    void print() const
    {
        cout << name << ": тал=" << side;
        cout << ", S=" << getArea();
        cout << ", P=" << getPerimeter() << endl;
        cout << "  Оройнууд: ";
        for (int i = 0; i < 4; i++)
        {
            vertices[i].print();
            cout << " ";
        }
        cout << endl;
    }
};

class Triangle : public TwoDShape
{
private:
    Point vertices[3];
    double side;

public:
    Triangle(const Point &topPoint, double s, const string &n)
        : TwoDShape(n), side(s)
    {
        double h = s * sqrt(3) / 2.0;
        vertices[0] = topPoint;
        vertices[1] = Point(topPoint.x - s / 2, topPoint.y + h);
        vertices[2] = Point(topPoint.x + s / 2, topPoint.y + h);
    }

    double getArea() const override
    {
        return (sqrt(3) / 4) * side * side;
    }

    double getPerimeter() const override
    {
        return 3 * side;
    }

    void print() const
    {
        cout << name << ": тал=" << side;
        cout << ", S=" << getArea();
        cout << ", P=" << getPerimeter() << endl;
        cout << "  Оройнууд: ";
        for (int i = 0; i < 3; i++)
        {
            vertices[i].print();
            cout << " ";
        }
        cout << endl;
    }
};

int main()
{
    Circle c(Point(0, 0), 5, "Тойрог");
    Square s(Point(0, 0), 4, "Квадрат");
    Triangle t(Point(0, 0), 6, "Зөв гурвалжин");

    c.print();
    s.print();
    t.print();

    return 0;
}