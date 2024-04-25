#include <iostream>
class BasePoint
{
	double X;
	double Y;
public:
	BasePoint() :X(0), Y(0) {};
	BasePoint(double _X, double _Y) :X(_X), Y(_Y) {};
	~BasePoint() {};

	virtual void printinfo(){
		std::cout << "(" << X << " , " << Y << ")\n";
	}

};

class Elipse : public BasePoint
{
    double a;
    double b;
public:
    Elipse() : BasePoint(0, 0), a(1), b(1) {};
    Elipse(double x, double y, double a, double b) : BasePoint(x, y), a(a), b(b) {};
    ~Elipse() {};
    double S() {
        double S = 3.14 * a * b;
        return S;
    }
    double P() {
        double P = 4 * (3.14*a*b + (a - b) *(a - b)) / (a + b);
        return P;
    }

};

class Circle : public BasePoint
{
    double R;
public:
    Circle() : BasePoint(0, 0), R(1) {};
    Circle(double x, double y, double r) : BasePoint(x,y), R(r) {};
    ~Circle() {};
    double S() {
        double S = 3.14 * R * R;
        return S;
    }
    double C() {
        double C = 2 * 3.14 * R;
        return C;
    }
};

int main()
{
    Elipse elipse(1, 2, 3, 4);
    Circle circle(0, 0, 5);

    std::cout << "Elipse centre:\n";
    elipse.printinfo();
    std::cout << "Circle centre:\n";
    circle.printinfo();

    std::cout << "Elipse S: " << elipse.S() << std::endl;
    std::cout << "Elipse P: " << elipse.P() << std::endl;

    std::cout << "Circle S: " << circle.S() << std::endl;
    std::cout << "Circle C: " << circle.C() << std::endl;

    return 0;
}

