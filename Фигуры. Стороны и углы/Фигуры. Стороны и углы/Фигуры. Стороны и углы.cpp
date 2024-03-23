#include <iostream>
#include <vector>
#include <typeinfo>

class Figure {
public:
    std::vector<double> getSides() const {
        return sides;
    }
    std::vector<double> getAngles() const {
        return angles;
    }
    virtual ~Figure() {}
    const char* getName() const {
        return name;
    }
protected:
    const char* name;
    std::vector<double> sides;
    std::vector<double> angles;
};

class Triangle : public Figure {
public:
    Triangle(double a, double b, double c, double A, double B, double C) {
        sides = { a, b, c };
        angles = { A, B, C };
        name = "Треугольник";
    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D) {
        sides = { a, b, c, d };
        angles = { A, B, C, D };
        name = "Четырёхугольник";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c) : Triangle(a, b, c, 90, 90, 90) {
        name = "Прямоугольный треугольник";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double c) : Triangle(a, b, c, 60, 60, 60) {
        name = "Равнобедренный треугольник";
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double a, double b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }
};

class Square : public Rectangle {
public:
    Square(double a) : Rectangle(a, a) {
        name = "Квадрат";
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A) : Quadrilateral(a, b, a, b, A, 180 - A, A, 180 - A) {
        name = "Параллелограмм";
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double a, double A) : Parallelogram(a, a, A) {
        name = "Ромб";
    }
};

void printInfo(const Figure* figure) {
    std::cout << figure->getName() << ":" << std::endl;
    std::vector<double> sides = figure->getSides();
    std::vector<double> angles = figure->getAngles();
    std::cout << "Стороны: ";
    for (size_t i = 0; i < sides.size(); ++i) {
        char angle = 'a' + i;
        std::cout << angle << "=" << sides[i] << " ";
    }
    std::cout << std::endl << "Углы: ";
    for (size_t i = 0; i < angles.size(); ++i) {
        char angle = 'A' + i;
        std::cout << angle << "=" << angles[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rightTriangle(10, 20, 30);
    IsoscelesTriangle isoscelesTriangle(10, 20, 10);
    EquilateralTriangle equilateralTriangle(30);
    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30);
    Rhombus rhombus(30, 30);

    std::vector<Figure*> figures = { &triangle, &rightTriangle, &isoscelesTriangle,
                                    &equilateralTriangle, &quadrilateral, &rectangle,
                                    &square, &parallelogram, &rhombus };

    for (const auto& figure : figures) {
        printInfo(figure);
    }

    return 0;
}