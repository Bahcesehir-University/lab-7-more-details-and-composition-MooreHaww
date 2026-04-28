// ============================================================
// Lab: More Details about Classes
// Course: Object-Oriented Programming (C++)
// Level: 2nd Year Engineering
// Duration: 60 minutes
// ============================================================

#include <iostream>
#include <string>
#include <cmath>

// ============================================================
// CLASS DEFINITIONS
// ============================================================

class Point {
private:
    double x;
    double y;
public:
    // TODO 1: Fixed initializer list
    Point(double x, double y) : x(x), y(y) {}

    // TODO 2: const getter for x
    double getX() const { return x; }

    // TODO 3: const getter for y
    double getY() const { return y; }

    // TODO 4: const display()
    void display() const {
        std::cout << "(" << x << ", " << y << ")";
    }

    // TODO 5: Rectangle is a friend class
    friend class Rectangle;
};


class Rectangle {
private:
    Point topLeft;
    Point bottomRight;
public:
    // TODO 6: Fixed initializer list
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {}

    // TODO 7: const getWidth() — uses direct member access via friendship
    double getWidth() const {
        return std::abs(bottomRight.x - topLeft.x);
    }

    // TODO 8: const getHeight()
    double getHeight() const {
        return std::abs(bottomRight.y - topLeft.y);
    }

    // TODO 9: const getArea()
    double getArea() const {
        return getWidth() * getHeight();
    }

    // TODO 10: const display()
    void display() const {
        std::cout << "Rectangle [ topLeft=";
        topLeft.display();
        std::cout << ", bottomRight=";
        bottomRight.display();
        std::cout << ", width=" << getWidth()
                  << ", height=" << getHeight()
                  << ", area=" << getArea() << " ]";
    }

    // TODO 11: isSameSize is a friend function
    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};


// TODO 12: implement isSameSize
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return (r1.getWidth()  == r2.getWidth() &&
            r1.getHeight() == r2.getHeight());
}


class ConstDemo {
private:
    int value;
public:
    // TODO 13: Fixed initializer list
    ConstDemo(int v) : value(v) {}

    // TODO 14: const getValue()
    int getValue() const { return value; }

    // TODO 15: NON-const doubleValue()
    void doubleValue() { value *= 2; }

    // TODO 16: const constGetDouble()
    int constGetDouble() const { return value * 2; }
};


// ============================================================
// MAIN
// ============================================================
int main() {
    // TODO 17: Point demo
    std::cout << "=== Point ===" << std::endl;
    Point p(3.0, 4.0);
    p.display();
    std::cout << std::endl;

    // TODO 18: Rectangle demo
    std::cout << "\n=== Rectangle ===" << std::endl;
    Rectangle r1(0, 0, 5, 3);
    Rectangle r2(1, 1, 6, 4);
    Rectangle r3(0, 0, 4, 3);

    std::cout << "r1: "; r1.display(); std::cout << std::endl;
    std::cout << "r2: "; r2.display(); std::cout << std::endl;
    std::cout << "r3: "; r3.display(); std::cout << std::endl;

    // TODO 19: isSameSize demo
    std::cout << "\n=== isSameSize ===" << std::endl;
    std::cout << "r1 same size as r2? "
              << (isSameSize(r1, r2) ? "Yes" : "No") << std::endl;
    std::cout << "r1 same size as r3? "
              << (isSameSize(r1, r3) ? "Yes" : "No") << std::endl;

    // TODO 20: ConstDemo — const vs non-const
    std::cout << "\n=== ConstDemo ===" << std::endl;
    ConstDemo cd(7);
    std::cout << "value        : " << cd.getValue()      << std::endl;
    std::cout << "constGetDouble: " << cd.constGetDouble() << std::endl;
    cd.doubleValue();
    std::cout << "after doubleValue(), value: " << cd.getValue() << std::endl;

    // TODO 21: const object — only const methods callable
    std::cout << "\n=== const ConstDemo object ===" << std::endl;
    const ConstDemo ccd(10);
    std::cout << "const obj value        : " << ccd.getValue()       << std::endl;
    std::cout << "const obj constGetDouble: " << ccd.constGetDouble() << std::endl;
    // ccd.doubleValue(); // <-- would NOT compile; non-const method on const object

    return 0;
}