#include <iostream>
#include <string>

using namespace std;

class Figure {
protected:
    int sides_count;
    string name;

public:
    Figure(int sides_count) : sides_count(sides_count), name("Фигура") {}

    int get_sides_count() const {
        return sides_count;
    }

    string get_name() const {
        return name;
    }
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3) {
        name = "Треугольник";
    }
};

class Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4) {
        name = "Четырёхугольник";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Figure figure(0);
    Triangle triangle;
    Quadrangle quadrangle;

    cout << "Количество сторон:" << endl;
    cout << figure.get_name() << ": " << figure.get_sides_count() << endl;
    cout << triangle.get_name() << ": " << triangle.get_sides_count() << endl;
    cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << endl;

    return 0;
}