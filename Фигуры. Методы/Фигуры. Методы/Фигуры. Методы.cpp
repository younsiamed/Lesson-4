#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Shape {
protected:
    string name;
    int sides;
public:
    Shape(string name, int sides) : name(name), sides(sides) {}

    virtual void print_info() {
        cout << name << ":" << endl;
        cout << (check() ? "Правильная" : "Неправильная") << endl;
        cout << "Количество сторон: " << sides << endl;
    }

    virtual bool check() {
        return sides == 0;
    }
};

class Figure {
protected:
    string name;
    int num_sides;
public:
    Figure(string name, int num_sides) : name(name), num_sides(num_sides) {}

    virtual void print_info() const {
        cout << "Фигура:\n";
        cout << (check() ? "Правильная\n" : "Неправильная\n");
        cout << "Количество сторон: " << num_sides << "\n";
    }

    virtual bool check() const {
        return num_sides == 0;
    }
};

class ZeroSidedFigure : public Figure {
public:
    ZeroSidedFigure() : Figure("Фигура", 0) {}

    virtual void print_info() const override {
        cout << "Фигура:\n";
        cout << "Правильная\n";
        cout << "Количество сторон: " << num_sides << "\n";
        cout << endl;
    }

    virtual bool check() const override {
        return Figure::check();
    }
};

class Triangle : public Shape {
private:
    map<char, int> sides_lengths;
    map<char, int> angles;
public:
    Triangle(string name, map<char, int> sides_lengths, map<char, int> angles)
        : Shape(name, 3), sides_lengths(sides_lengths), angles(angles) {}

    void print_info() override {
        Shape::print_info();
        if (sides == 3) {
            cout << "Стороны:";
            for (auto& side : sides_lengths)
                cout << " " << side.first << "=" << side.second;
            cout << endl;

            cout << "Углы:";
            for (auto& angle : angles)
                cout << " " << angle.first << "=" << angle.second;
            cout << endl;
        }
    }

    bool check() override {
        if (sides != 3)
            return false;
        int sum_of_angles = 0;
        for (auto& angle : angles)
            sum_of_angles += angle.second;
        return sum_of_angles == 180;
    }
};

class Quadrilateral : public Shape {
private:
    map<char, int> sides_lengths;
    map<char, int> angles;
public:
    Quadrilateral(string name, map<char, int> sides_lengths, map<char, int> angles)
        : Shape(name, 4), sides_lengths(sides_lengths), angles(angles) {}

    void print_info() override {
        Shape::print_info();
        if (sides == 4) {
            cout << "Стороны:";
            for (auto& side : sides_lengths)
                cout << " " << side.first << "=" << side.second;
            cout << endl;

            cout << "Углы:";
            for (auto& angle : angles)
                cout << " " << angle.first << "=" << angle.second;
            cout << endl;
        }
    }

    bool check() override {
        if (sides != 4)
            return false;
        int sum_of_angles = 0;
        for (auto& angle : angles)
            sum_of_angles += angle.second;
        return sum_of_angles == 360;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    ZeroSidedFigure zeroSidedFigure;
    zeroSidedFigure.print_info();
    Triangle triangle1("Треугольник", { {'a', 10}, {'b', 20}, {'c', 30} }, 
        { {'A', 50}, {'B', 60}, {'C', 70} });

    Triangle triangle2("Прямоугольный треугольник", { {'a', 10}, {'b', 20}, {'c', 30} },
        { {'A', 50}, {'B', 60}, {'C', 90} });

    Triangle triangle3("Прямоугольный треугольник", { {'a', 10}, {'b', 20}, {'c', 30} }, 
        { {'A', 50}, {'B', 40}, {'C', 90} });

    Triangle triangle4("Равнобедренный треугольник", { {'a', 10}, {'b', 20}, {'c', 10} }, 
        { {'A', 50}, {'B', 60}, {'C', 50} });

    Triangle triangle5("Равносторонний треугольник", { {'a', 30}, {'b', 30}, {'c', 30} }, 
        { {'A', 60}, {'B', 60}, {'C', 60} });

    Quadrilateral quadrilateral1("Четырёхугольник", { {'a', 10}, {'b', 20}, {'c', 30}, {'d', 40} }, 
        { {'A', 50}, {'B', 60}, {'C', 70}, {'D', 80} });

    Quadrilateral quadrilateral2("Прямоугольник", { {'a', 10}, {'b', 20}, {'c', 10}, {'d', 20} }, 
        { {'A', 90}, {'B', 90}, {'C', 90}, {'D', 90} });

    Quadrilateral quadrilateral3("Квадрат", { {'a', 20}, {'b', 20}, {'c', 20}, {'d', 20} }, 
        { {'A', 90}, {'B', 90}, {'C', 90}, {'D', 90} });

    Quadrilateral quadrilateral4("Параллелограмм", { {'a', 20}, {'b', 30}, {'c', 20}, {'d', 30} }, 
        { {'A', 30}, {'B', 40}, {'C', 30}, {'D', 40} });

    Quadrilateral quadrilateral5("Ромб", { {'a', 30}, {'b', 30}, {'c', 30}, {'d', 30} }, 
        { {'A', 30}, {'B', 40}, {'C', 30}, {'D', 40} });

    vector<Shape*> figures = { &triangle1, &triangle2, &triangle3, &triangle4, &triangle5, &quadrilateral1, &quadrilateral2, &quadrilateral3, &quadrilateral4, &quadrilateral5 };

    for (auto figure : figures) {
        figure->print_info();
        cout << endl;
    }

    return 0;
}