#include <iostream>
#include <string>
using namespace std;

class Vector
{
private:
    double x;
    double y;

public:
    Vector(double a, double b) : x(a), y(b)
    {
    }
    Vector operator+=(const Vector &other)
    {
        x += other.x;
        y += other.y;

        return *this;
    }
    void display()
    {
        cout << "x : " << x << ", y: " << y << endl;
    }
};

int main()
{
    Vector c(5.05, 6);
    Vector c2(4, 6);
    c += c2;
    c.display();
}